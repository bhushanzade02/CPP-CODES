#include <mpi.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int rank, nprocs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    int rowsA = 0, colsA = 0, colsB = 0;
    vector<int> A, B;

    if (rank == 0)
    {
        ifstream fin("input.txt");
        if (!fin.is_open())
        {
            cerr << "Error: Unable to open input file.\n";
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        // Read dimensions
        fin >> rowsA >> colsA;
        A.resize(rowsA * colsA);
        for (int i = 0; i < rowsA * colsA; i++)
            fin >> A[i];

        fin >> colsB;
        B.resize(colsA * colsB);
        for (int i = 0; i < colsA * colsB; i++)
            fin >> B[i];

        fin.close();
    }

    // Broadcast matrix sizes
    MPI_Bcast(&rowsA, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&colsA, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&colsB, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank != 0)
        B.resize(colsA * colsB);

    // Check divisibility for even row distribution
    if (rowsA % nprocs != 0)
    {
        if (rank == 0)
            cerr << "Error: Number of rows in A must be divisible by number of processes.\n";
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    int localRows = rowsA / nprocs;
    vector<int> A_local(localRows * colsA);

    // Scatter matrix A rows
    MPI_Scatter(A.data(), localRows * colsA, MPI_INT,
                A_local.data(), localRows * colsA, MPI_INT, 0, MPI_COMM_WORLD);

    // Broadcast entire B to all processes
    MPI_Bcast(B.data(), colsA * colsB, MPI_INT, 0, MPI_COMM_WORLD);

    // Local computation for partial C
    vector<int> C_local(localRows * colsB, 0);
    for (int i = 0; i < localRows; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            int val = 0;
            for (int k = 0; k < colsA; k++)
                val += A_local[i * colsA + k] * B[k * colsB + j];
            C_local[i * colsB + j] = val;
        }
    }

    // Gather result on rank 0
    vector<int> C;
    if (rank == 0)
        C.resize(rowsA * colsB);

    MPI_Gather(C_local.data(), localRows * colsB, MPI_INT,
               C.data(), localRows * colsB, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        string outFile = "output_" + to_string(nprocs) + "_procs.txt";
        ofstream fout(outFile);
        if (!fout.is_open())
        {
            cerr << "Error: Unable to open output file.\n";
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        cout << "\nResultant Matrix C (" << nprocs << " processes):\n";
        fout << "Resultant Matrix C (" << nprocs << " processes):\n";
        for (int i = 0; i < rowsA; i++)
        {
            for (int j = 0; j < colsB; j++)
            {
                cout << C[i * colsB + j] << " ";
                fout << C[i * colsB + j] << " ";
            }
            cout << endl;
            fout << endl;
        }

        fout.close();
        cout << "\nOutput written successfully to " << outFile << endl;
    }

    MPI_Finalize();
    return 0;
}
