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

    int rows = 0, cols = 0, tmp = 0;
    vector<int> matrix;
    vector<int> vec;

    if (rank == 0)
    {
        ifstream fin("input.txt");
        if (!fin.is_open())
        {
            cerr << "Error: Unable to open input file.\n";
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        // first three integers are rows, cols and  dummy variable
        fin >> rows >> cols >> tmp;

        matrix.resize(rows * cols);
        vec.resize(cols);

        // reading matrix elements
        for (int i = 0; i < rows * cols; i++)
            fin >> matrix[i];

        // reading vector elements
        for (int i = 0; i < cols; i++)
            fin >> vec[i];

        fin.close();
    }

    // Broadcast matrix dimensions to all processes
    MPI_Bcast(&rows, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&cols, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank != 0)
        vec.resize(cols);

    // Broadcast vector to all processes
    MPI_Bcast(vec.data(), cols, MPI_INT, 0, MPI_COMM_WORLD);

    // Determine number of rows for each process
    int baseRows = rows / nprocs;
    int extra = rows % nprocs;
    int localRows = baseRows + (rank < extra ? 1 : 0);
    int localSize = localRows * cols;

    // calculate send counts and displacements
    vector<int> sendCounts, displs, recvCounts, recvDispls;
    if (rank == 0)
    {
        sendCounts.resize(nprocs);
        displs.resize(nprocs);
        recvCounts.resize(nprocs);
        recvDispls.resize(nprocs);

        int offset = 0, disp = 0;
        for (int i = 0; i < nprocs; i++)
        {
            int r = baseRows + (i < extra ? 1 : 0);
            sendCounts[i] = r * cols;
            displs[i] = offset;
            offset += sendCounts[i];

            recvCounts[i] = r;
            recvDispls[i] = disp;
            disp += recvCounts[i];
        }
    }

    // Allocate space for local matrix block
    vector<int> localMatrix(localSize);

    // Distribute rows among all processes
    MPI_Scatterv(matrix.data(), sendCounts.data(), displs.data(), MPI_INT,
                 localMatrix.data(), localSize, MPI_INT, 0, MPI_COMM_WORLD);

    // Compute local matrix-vector multiplication
    vector<int> localResult(localRows, 0);
    for (int i = 0; i < localRows; i++)
    {
        for (int j = 0; j < cols; j++)
            localResult[i] += localMatrix[i * cols + j] * vec[j];
    }

    // gather all partial results at root process
    vector<int> finalResult;
    if (rank == 0)
        finalResult.resize(rows);

    MPI_Gatherv(localResult.data(), localRows, MPI_INT,
                finalResult.data(), recvCounts.data(), recvDispls.data(),
                MPI_INT, 0, MPI_COMM_WORLD);

    // Root process writes the output
    if (rank == 0)
    {
        ofstream fout("output.txt");
        if (!fout.is_open())
        {
            cerr << "Error: Unable to open output file.\n";
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        cout << "\nResultant Vector (Matrix × Vector):\n";
        fout << "Resultant Vector:\n";
        for (int i = 0; i < rows; i++)
        {
            cout << finalResult[i] << " ";
            fout << finalResult[i] << "\n";
        }
        cout << "\n\nComputation completed successfully.\n";
        fout.close();
    }

    MPI_Finalize();
    return 0;
}
