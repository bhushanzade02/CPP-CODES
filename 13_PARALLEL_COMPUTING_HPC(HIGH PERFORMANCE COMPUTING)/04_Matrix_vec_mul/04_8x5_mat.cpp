#include <iostream>
#include <mpi.h>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    MPI_Status status;
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    cout << "rank : " << rank << " " << " no of processor :" << size << "  " << endl;
    int M = 8;
    int N = 5;
    int norows = M / size;
    int sendcount = norows * N;
    vector<int> A;
    vector<int> x(N);
    vector<int> row(sendcount);
    vector<int> ans(M);

    if (rank == 0)
    {
        A.resize(M * N);
        A = {1, 2, 3, 4, 5,
             2, 4, 6, 8, 10,
             3, 6, 9, 12, 15,
             4, 8, 12, 16, 20,
             5, 10, 15, 20, 25,
             6, 12, 18, 24, 30,
             7, 14, 21, 28, 35,
             8, 16, 24, 32, 40};

        x = {10, 11, 12, 13, 14};

        cout << "A.size() " << A.size() << endl;
        cout << "x.size() " << x.size() << endl;
    }

    // step 2 : sending A matrics and vector x to all processes
    MPI_Scatter(A.data(), sendcount, MPI_INT, row.data(), sendcount, MPI_INT, 0, MPI_COMM_WORLD);

    // step 3 : sending vector x to all processes
    MPI_Bcast(x.data(), N, MPI_INT, 0, MPI_COMM_WORLD);

    // step 4 : calcualting multiplication each row independently
    vector<int> result(norows);
    for (int i = 0; i < norows; i++)
    {
        int b = 0;
        for (int j = 0; j < N; j++)

        {
            b += row[j+(i*N)] * x[j];
        }
        result[i]=b;
    }
    // cout << "B at " << rank << " is : " << b << endl;

    // Gather element of vector b stored at rank 0
    MPI_Gather(result.data(), norows, MPI_INT, ans.data(),norows,  MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        cout << endl;
        cout << "Vector b: ";
        for (int n : ans)
            cout << n << " ";
        cout << endl;
    }

    MPI_Finalize();
    return 0;
}