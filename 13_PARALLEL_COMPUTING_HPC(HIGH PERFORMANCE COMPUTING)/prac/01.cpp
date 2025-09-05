#include <vector>
#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char *argv[])
{

    MPI_Init(&argc, &argv);
    int size, rank;
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    vector<int> A;
    int n = 100;
    int part = n / size;
    int remainder = n % size;

    if (rank == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            A.push_back(i);
        }

        for (int p = 1; p < size; p++)
        {
            int count = (p < remainder) ? (part + 1) : (part);
           int start_idx = p * part + min(p, remainder);

            MPI_Send(A.data() + start_idx, count, MPI_INT, p, 1, MPI_COMM_WORLD);
        }

        int lsum = 0;
        int rank0_count = (0 < remainder) ? (part + 1) : (part);
        for (int i = 0; i < rank0_count; i++)
        {
            lsum += A[i];
        }

        int total_sum = lsum;
        for (int i = 1; i < size; i++)
        {
            int sum;
            MPI_Recv(&sum, 1, MPI_INT, i, 2, MPI_COMM_WORLD, &status);

            total_sum += sum;
        }

        cout << "FINAL TOTAL SUM IS " << total_sum << endl;
    }

    if (rank != 0)
    {

        int count = (rank < remainder) ? (part + 1) : part;

        vector<int> B(count);

        MPI_Recv(B.data(), count, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);

        int local_sum = 0;
        for (int i = 0; i < count; i++)
        {
            local_sum += B[i];
        }

        MPI_Send(&local_sum, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}