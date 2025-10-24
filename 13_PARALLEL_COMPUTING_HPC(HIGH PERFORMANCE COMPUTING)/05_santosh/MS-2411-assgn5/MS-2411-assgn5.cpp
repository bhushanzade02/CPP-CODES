	#include <iostream>
	#include <fstream>
	#include <mpi.h>
	#include <vector>
	using namespace std;

	int main(int argc, char *argv[])
	{
		// MPI environment setup
		MPI_Init(&argc, &argv);
		int rank, size;
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		MPI_Comm_size(MPI_COMM_WORLD, &size);

		int m, n, p;
		vector<int> A, B;
		if (rank == 0)
		{
			// Generating data at rank 0
			ifstream fin("input.txt");
			if (!fin)
			{
				cerr << "Error opening file.\n";
				return 1;
			}

			// reading dimensions of matrix A
			fin >> m >> n;
			A.resize(m * n);
			
			// reading matrix A
			for (int i = 0; i < (m * n); i++)
			fin >> A[i];
			
			// reading dimensions of matrix B
			fin >> p;
			B.resize(n * p);

			// reading matrix B
			for (int i = 0; i < (n * p); i++)
				fin >> B[i];

			fin.close();
		}

		// Broadcasting Matrix dimensions on all processes
		MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Bcast(&p, 1, MPI_INT, 0, MPI_COMM_WORLD);

		if (rank != 0)
		{
			// resizing matrix B
			B.resize(n * p);
		}

		// condition to check rows of A are divided by number of processes
		if (m % size != 0)
		{
			if (rank == 0)
				cerr << "Error: Rows of matrix A not divisible by number of processes.." << endl;
			MPI_Abort(MPI_COMM_WORLD, 1);
		}

		// Number of rows to be sent on each process
		int noRows = m / size;

		// sending noRows rows to each process
		vector<int> localA(noRows * n, 0);
		MPI_Scatter(A.data(), noRows * n, MPI_INT, localA.data(), noRows * n, MPI_INT, 0, MPI_COMM_WORLD);

		// Broadcasting Matrix B on every process
		MPI_Bcast(B.data(), n * p, MPI_INT, 0, MPI_COMM_WORLD);

		// Locally computing the matrix-matrix multiplication
		vector<int> localC(noRows * p, 0);
		for (int i = 0; i < noRows; i++)
		{
			for (int j = 0; j < p; j++)
			{
				int sum = 0;
				for (int k = 0; k < n; k++)
					sum += localA[(i * n) + k] * B[(k * p) + j];
				localC[(i * p) + j] = sum;
			}
		}

		// Gathering local C data at rank 0
		vector<int> C;
		if (rank == 0)
			C.resize(m * p);
		MPI_Gather(localC.data(), noRows * p, MPI_INT, C.data(), noRows * p, MPI_INT, 0, MPI_COMM_WORLD);

		if (rank == 0)
		{
			string filename = "outputUsing"+to_string(size)+"processes.txt";
			ofstream fout(filename);

			cout << "Resultant matrix C using " << size << " processes : " << endl;
			fout << "Resultant matrix C using " << size << " processes : " << endl;

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < p; j++)
				{
					cout << C[i * p + j] << " ";
					fout << C[i * p + j] << " ";
				}
				cout << endl;
				fout << endl;
			}
			fout.close();
		}

		MPI_Finalize();
		return 0;
	}