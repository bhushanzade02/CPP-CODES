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

    int rows = 3, cols = 3;
    vector<int> A;
    vector<int> x(cols);
    vector<int> b(cols);
    vector<int> row(cols);

    // step1 : data generatio process 0
    if (rank == 0)
    {
        A.resize(rows * cols);
        A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        x = {10, 11, 12};
        cout << "vector A size : " << A.size();
        cout << endl;
        cout << "vector x size : " << x.size();
    }

    // step 2 : sending A matrics and vector x to all processes
    MPI_Scatter(A.data(), cols, MPI_INT, row.data(), cols, MPI_INT, 0, MPI_COMM_WORLD);

    // step 3 : sending vector x to all processes
    MPI_Bcast(x.data(), cols, MPI_INT, 0, MPI_COMM_WORLD);

    // step 4 : calcualting multiplication each row independently
    int brow = 0;
    for (int i = 0; i < cols; i++)
    {
        brow = brow + row[i] * x[i];
    }

    cout << "B at" << rank << "is" << brow << endl;

    // elemenst of vector b stored at rank 0
    MPI_Gather(&brow, 1, MPI_INT, b.data(), 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        cout << endl;
        cout << " vector b [ ";
        for (int n : b)
        {
            cout << n << " ";
        }
        cout<< " ] ";
        cout << endl;
    }

    
    MPI_Finalize();
    return 0;
}