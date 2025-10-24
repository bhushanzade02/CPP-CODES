#include <iostream>
#include <mpi.h>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    MPI_Status status;
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int m, n, p;
    vector<int> data;
    vector<int> vec;
    if (rank == 0)
    {
        // Reading data from a input file for matrix and the vector
        ifstream fin("input.txt");
        if (!fin)
        {
            cerr << "Error opening file.\n";
            return 1;
        }
        fin >> m >> n >> p;
        data.resize(m * n);
        vec.resize(n);

        for (int i = 0; i < (m * n); i++)
            fin >> data[i];

        for (int i = 0; i < n; i++)
            fin >> vec[i];

        fin.close();
    }

    // Broadcasting Matrix dimensions on all processes
	MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&p, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank != 0)
	{
		// resizing vector
		vec.resize(n);
	}

    int part = m / size, rem = m % size;
    int noRows = rank < rem ? part + 1 : part;
    int sendCount = noRows * n;
    
    vector<int> sendcounts;
    vector<int> displs;
    vector<int> row(sendCount);
    vector<int> recvCounts;
    vector<int> recvDisp;

    if (rank == 0)
    {
        // calculating sendcount and displacement to send data to all other processes
        sendcounts.resize(size);
        displs.resize(size);
        int offset = 0;
        for (int i = 0; i < size; i++)
        {
            int rowsForProc = part + (i < rem ? 1 : 0);
            sendcounts[i] = rowsForProc * n;
            displs[i] = offset;
            offset += sendcounts[i];
        }

        // calculating recv count and recv displacement for gathering at process 0
        recvCounts.resize(size);
        recvDisp.resize(size);
        offset = 0;
        for (int i = 0; i < size; i++)
        {
            recvCounts[i] = part + (i < rem ? 1 : 0);
            recvDisp[i] = offset;
            offset += recvCounts[i];
        }
    }

    // sending data to all the other processes
    MPI_Scatterv(data.data(), sendcounts.data(), displs.data(), MPI_INT, row.data(), sendCount, MPI_INT, 0, MPI_COMM_WORLD);

    // sending vector to all the processes
    MPI_Bcast(vec.data(), n, MPI_INT, 0, MPI_COMM_WORLD);

    // calculating the multiplication for each row independently
    vector<int> result(noRows);
    for (int i = 0; i < noRows; i++)
    {
        int b = 0;
        for (int j = 0; j < n; j++)
            b += row[j + (i * n)] * vec[j];

        result[i] = b;
    }

    // element of ans vector b to be stored at process 0
    vector<int> ans;
    if (rank == 0)
        ans.resize(m);
    MPI_Gatherv(result.data(), noRows, MPI_INT, ans.data(), recvCounts.data(), recvDisp.data(), MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        // writing output data in file
        ofstream fout("output.txt");
        if (!fout)
        {
            cerr << "Error opening file.\n";
            return 1;
        }

        cout << endl;
        cout << "Resultant Vector C: " << endl;
        fout << "Resultant Vector C: " << endl;
        for (int n : ans)
        {
            fout << n << endl;
            cout << n << " ";
        }
        cout << endl
             << endl;
        cout << "Output is written in file successfully..!" << endl;

        fout.close();
    }

    MPI_Finalize();
}