#include <vector>
#include <iostream>
#include <mpi.h>
#include<algorithm>
using namespace std;


int main(int argc, char *argv[])
{

    MPI_Init(&argc, &argv);
    int size, rank;
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    vector<long long> A;
    long long n;

    if (rank == 0)
    {
        cout << "enter the Value of N so we can calculate sum of N numbers: " << endl;
        cin >> n;
    }

    MPI_Bcast(&n, 1, MPI_LONG_LONG, 0, MPI_COMM_WORLD);
    long long part = n / size;
    long long remainder = n % size;

    if (rank == 0)
    {
        for (long long i = 1; i <= n; i++)
        {
            A.push_back(i);
        }

        for (int p = 1; p < size; p++)
        {
            long long count = (p < remainder) ? (part + 1) : (part);
            long long start_idx = (long long )p * part + min(p, (int)remainder);

            MPI_Send(A.data() + start_idx, (int)count, MPI_LONG_LONG, p, 1, MPI_COMM_WORLD);
        }

        long long lsum = 0;
        long long rank0_count = (0 < remainder) ? (part + 1) : (part);
        for (long long i = 0; i < rank0_count; i++)
        {
            lsum += A[i];
        }

        long long total_sum = lsum;
        for (int i = 1; i < size; i++)
        {
            long long sum;
            MPI_Recv(&sum, 1, MPI_LONG_LONG, i, 2, MPI_COMM_WORLD, &status);

            total_sum += sum;
        }

        cout << "FINAL TOTAL SUM IS " << total_sum << endl;
    }

    if (rank != 0)
    {

        long long count = (rank < remainder) ? (part + 1) : part;

        vector<long long> B(count);

        MPI_Recv(B.data(), (int)count, MPI_LONG_LONG, 0, 1, MPI_COMM_WORLD, &status);

        long long local_sum = 0;
        for (long long i = 0; i < count; i++)
        {
            local_sum += B[i];
        }

        MPI_Send(&local_sum, 1, MPI_LONG_LONG, 0, 2, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}