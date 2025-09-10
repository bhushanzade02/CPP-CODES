// MS-2301-assgn2.cPP
// Replace MS-2301 with your roll number in filename before submission.
//
// Parallel Simpson's 3/8 rule using MPI
// Function: f(x) = x^2 * exp(-x), integral over [0,4]
// Intervals: 12, 20, 40, 80 (general n also works)
//
// Uses ONLY basic MPI functions: MPI_Init, MPI_Comm_rank, MPI_Comm_size,
// MPI_Send, MPI_Recv, MPI_Finalize.
// NO MPI_Barrier, NO fancy MPI functions.

#include <mpi.h>
#include <iostream>
#include <cmath>
#include <iomanip>

double f(double x) {
    return x * x * std::exp(-x);
}

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double a = 0.0, b = 4.0;
    int intervals_list[4] = {12, 20, 40, 80};

    if (rank == 0) {
        std::cout << std::fixed << std::setprecision(10);
        std::cout << "Parallel Simpson's 3/8 Rule\n";
        std::cout << "Function: x^2 * exp(-x), Interval: [0,4]\n";
        std::cout << "Processes: " << size << "\n\n";
    }

    for (int n : intervals_list) {
        double h = (b - a) / n;

        // Each process computes over its chunk of nodes
        int chunk = n / size;
        int start = rank * chunk;
        int end = (rank == size - 1) ? n : (start + chunk);

        double local_sum = 0.0;

        for (int i = start; i <= end; i++) {
            double x = a + i * h;
            double fx = f(x);
            int coef;

            if (i == 0 || i == n) coef = 1;
            else if (i % 3 == 0) coef = 2;
            else coef = 3;

            local_sum += coef * fx;
        }

        // Collect results manually
        if (rank == 0) {
            double total_sum = local_sum;
            for (int p = 1; p < size; p++) {
                double recv_val;
                MPI_Recv(&recv_val, 1, MPI_DOUBLE, p, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                total_sum += recv_val;
            }
            double integral = (3.0 * h / 8.0) * total_sum;
            std::cout << "n = " << std::setw(3) << n
                      << " -> Integral ≈ " << integral << "\n";
        } else {
            MPI_Send(&local_sum, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
        }
    }

    if (rank == 0) {
        std::cout << "\nDone.\n";
    }

    MPI_Finalize();
    return 0;
}


































// MS-2301-assgn2.cPP
// Replace MS-2301 with your roll number in filename before submission.

#include <mpi.h>
#include <iostream>
#include <cmath>
#include <iomanip>

double func(double x) {
    return x * x * std::exp(-x);
}

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int r, p;
    MPI_Comm_rank(MPI_COMM_WORLD, &r);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    double a = 0.0, b = 4.0;
    int n_list[4] = {12, 20, 40, 80};

    if (r == 0) {
        std::cout << std::fixed << std::setprecision(10);
        std::cout << "Parallel Simpson's 3/8 Rule\n";
        std::cout << "f(x) = x^2 * exp(-x), Interval: [0,4]\n";
        std::cout << "Processes: " << p << "\n\n";
    }

    for (int n : n_list) {
        double h = (b - a) / n;

        int part = n / p;
        int st = r * part;
        int en = (r == p - 1) ? n : (st + part);

        double lsum = 0.0;

        for (int i = st; i <= en; i++) {
            double x = a + i * h;
            double fx = func(x);
            int c;

            if (i == 0 || i == n) c = 1;
            else if (i % 3 == 0) c = 2;
            else c = 3;

            lsum += c * fx;
        }

        if (r == 0) {
            double tsum = lsum;
            for (int k = 1; k < p; k++) {
                double val;
                MPI_Recv(&val, 1, MPI_DOUBLE, k, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                tsum += val;
            }
            double res = (3.0 * h / 8.0) * tsum;
            std::cout << "n = " << std::setw(3) << n
                      << " -> Integral ≈ " << res << "\n";
        } else {
            MPI_Send(&lsum, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
        }
    }

    if (r == 0) std::cout << "\nDone.\n";

    MPI_Finalize();
    return 0;
}
