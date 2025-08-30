#include<vector>
#include<mpi.h>
#include<iostream>
using namespace std;


int main(int argc, char* argv[])
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    cout << size<<endl;

    int n = 100;
    int part = n / size;      // integer division
    // NOTE: we do NOT change non-zero ranks' code — they still expect 'part' elements.

    if (rank == 0)
    {
        vector<int> A;
        for (int i = 1; i <= n; i++) A.push_back(i);

        // send equal 'part' sized chunks to other processes
        for (int p = 1; p < size; p++) {
            MPI_Send(A.data() + p * part, part, MPI_INT, p, 1, MPI_COMM_WORLD);
        }

        // compute local sum for rank 0 for its chunk (first 'part' elements)
        int lsum = 0;
        for (int i = 0; i < part; i++) {
            lsum += A[i];
        }

        // add the remainder elements (if any) to rank 0's sum
        int rem = n % size;                 // leftover count
        int rem_start = size * part;        // index of first leftover element
        for (int i = rem_start; i < n; i++) {
            lsum += A[i];
        }

        // receive partial sums from other processes and accumulate
        int total_sum = lsum;
        for (int i = 1; i < size; i++) {
            int sum;
            MPI_Recv(&sum, 1, MPI_INT, i, 2, MPI_COMM_WORLD, &status);
            total_sum += sum;
        }

        cout << "Rank 0 local sum (including remainder) = " << lsum << endl;
        cout << "TOTAL SUM = " << total_sum << endl;
    }

    if (rank != 0)
    {
        vector<int> B(part);

        MPI_Recv(B.data(), part, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);

        int lsum = 0;
        for (int i = 0; i < part; i++) {
            lsum += B[i];
        }

        MPI_Send(&lsum, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
