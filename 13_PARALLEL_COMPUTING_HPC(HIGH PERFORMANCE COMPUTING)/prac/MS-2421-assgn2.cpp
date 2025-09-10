#include <mpi.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

double f(double x) {
    return x * x * exp(-x);
}

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    int size, rank;
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    double a = 0.0, b = 4.0;
    int n_list[4] = {12, 20, 40, 80};

    if (rank == 0) {
        cout << fixed << setprecision(10);
        cout << "Parallel Simpson's 3/8 Rule\n";
        cout << "Function: f(x) = x^2 * exp(-x), Interval [0,4]\n";
        cout << "Processes: " << size << "\n\n";
    }

    for (int n : n_list) {
        double h = (b - a) / n;

        // Divide work
        int part = n / size;
        int rem = n % size;

        if (rank == 0) {
            // Precompute all function values with coefficients
            vector<double> vals(n + 1);
            for (int i = 0; i <= n; i++) {
                double x = a + i * h;
                int coef = (i == 0 || i == n) ? 1 : (i % 3 == 0 ? 2 : 3);
                vals[i] = coef * f(x);
            }

            // Send chunks
            for (int p = 1; p < size; p++) {
                int cnt = (p < rem) ? (part + 1) : part;
                int start_idx = p * part + min(p, rem);
                MPI_Send(vals.data() + start_idx, cnt, MPI_DOUBLE, p, 1, MPI_COMM_WORLD);
            }

            // Rank 0 local sum
            int cnt0 = (0 < rem) ? (part + 1) : part;
            double lsum = 0.0;
            for (int i = 0; i < cnt0; i++) {
                lsum += vals[i];
            }

            // Collect results
            double total = lsum;
            for (int p = 1; p < size; p++) {
                double psum;
                MPI_Recv(&psum, 1, MPI_DOUBLE, p, 2, MPI_COMM_WORLD, &status);
                total += psum;
            }

            double result = (3.0 * h / 8.0) * total;
            cout << "n = " << setw(3) << n << " -> Approx integral = " << result << endl;
        }

        if (rank != 0) {
            int cnt = (rank < rem) ? (part + 1) : part;
            vector<double> buf(cnt);

            MPI_Recv(buf.data(), cnt, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD, &status);

            double lsum = 0.0;
            for (int i = 0; i < cnt; i++) {
                lsum += buf[i];
            }

            MPI_Send(&lsum, 1, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD);
        }
    }

    if (rank == 0) {
        cout << "\nDone.\n";
    }

    MPI_Finalize();
    return 0;
}
