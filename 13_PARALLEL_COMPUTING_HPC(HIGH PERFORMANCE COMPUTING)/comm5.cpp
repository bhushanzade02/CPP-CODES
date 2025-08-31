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
    int remainder = n % size;  

    if (rank == 0)
    {
        vector<int> A;
        for (int i = 1; i <= n; i++)
            A.push_back(i);

        // Send data to all other processors
        int start = 0;
        for (int p = 1; p < size; p++)
        {
            int extra = (p < remainder) ? 1 : 0;  // give extra number if p < remainder
            int send_count = part + extra;

            start += (p == 1 ? part + (0 < remainder) : part + ((p - 1) < remainder));
            MPI_Send(A.data() + start, send_count, MPI_INT, p, 1, MPI_COMM_WORLD);
        }

        // Local sum for process 0
        int local_count = part + (0 < remainder ? 1 : 0);
        int lsum = 0;
        for (int i = 0; i < local_count; i++)
            lsum += A[i];

        int total_sum = lsum;

        // Collect sums
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
        int extra = (rank < remainder) ? 1 : 0;
        int recv_count = part + extra;

        vector<int> B(recv_count);

        MPI_Recv(B.data(), recv_count, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);

        int lsum = 0;
        for (int i = 0; i < recv_count; i++)
            lsum += B[i];

        MPI_Send(&lsum, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}
