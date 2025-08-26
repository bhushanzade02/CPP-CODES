#include <vector>
#include <mpi.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{

    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int n = 100;
    int part = n / size;

    if (rank == 0)
    {
        vector<int> A;
        for (int i = 1; i <= n; i++)
            A.push_back(i);

            
        for (int i = 1; i < size; i++)
            MPI_Send(A.data() + i * part, part, MPI_INT, i, 1, MPI_COMM_WORLD);

        int lsum = 0;
        for (int i = 0; i < part; i++)
            lsum += A[i];

        int total_sum = lsum;
        for (int i = 1; i < size; i++)
        {

            int sum;
            MPI_Recv(&sum, 1, MPI_INT, i, 2, MPI_COMM_WORLD, &status);
            total_sum += sum;
        }
        cout << "TOTAL SUM " << total_sum << endl;
    }

    if (rank != 0)
    {
        vector<int> B(part);

        MPI_Recv(B.data(), part, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);

        int lsum = 0;

        for (int i = 0; i < part; i++)
            lsum += B[i];

        MPI_Send(&lsum, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}