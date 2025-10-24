#include <iostream>
#include<fstream>
#include <mpi.h>
#include <algorithm>
#include <vector>
using namespace std;

// serial partiton
int partition(vector<int> &A, int start, int end)
{
	int pivot = A[end];
	int i = start - 1;
	for (int j = start; j < end; j++)
	{
		if (A[j] < pivot)
		{
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[end]);
	return i + 1;
}

// serial quciksort
void quickSort(vector<int> &A, int start, int end)
{
	if (start < end)
	{
		int index = partition(A, start, end);
		quickSort(A, start, index - 1);
		quickSort(A, index + 1, end);
	}
}

void parallelQuickSort(vector<int> &A, MPI_Comm comm)
{
	int rank, size;
	MPI_Comm_rank(comm, &rank);
	MPI_Comm_size(comm, &size);

	if (size == 1)
	{
		quickSort(A, 0, A.size() - 1);
		return;
	}

	// choosing pivot and sending to all using broadcast
	int pivot;
	if (rank == 0)
		pivot = (A.empty()) ? 0 : A.back();

	MPI_Bcast(&pivot, 1, MPI_INT, 0, comm);

	// local partitioning
	vector<int> left, right;
	for (int n : A)
	{
		if (n < pivot)
			left.push_back(n);
		else
			right.push_back(n);
	}

	// exchaning data between paired processes
	vector<int> recvData;
	int partner, half = size / 2;

	if (rank < half)
	{
		partner = rank + half;

		int sendSize = right.size();
		int recvSize;

		MPI_Sendrecv(&sendSize, 1, MPI_INT, partner, 0, &recvSize, 1, MPI_INT, partner, 0, comm, MPI_STATUS_IGNORE);

		recvData.resize(recvSize);

		MPI_Sendrecv(right.data(), sendSize, MPI_INT, partner, 1,
					 recvData.data(), recvSize, MPI_INT, partner, 1,
					 comm, MPI_STATUS_IGNORE);

		A = left;
		A.insert(A.end(), recvData.begin(), recvData.end());
	}
	else
	{
		partner = rank - half;

		int sendSize = left.size();
		int recvSize;
		MPI_Sendrecv(&sendSize, 1, MPI_INT, partner, 0, &recvSize, 1, MPI_INT, partner, 0, comm, MPI_STATUS_IGNORE);

		recvData.resize(recvSize);
		MPI_Sendrecv(left.data(), sendSize, MPI_INT, partner, 1, recvData.data(), recvSize, MPI_INT, partner, 1,
					 comm, MPI_STATUS_IGNORE);

		A = right;
		A.insert(A.end(), recvData.begin(), recvData.end());
	}

	// spliting the communicator for vales <= pivot and values > pivot
	int color = rank < half ? 0 : 1;
	MPI_Comm newComm;
	MPI_Comm_split(comm, color, rank, &newComm);

	parallelQuickSort(A, newComm);

	// marks the communication object for deallocation
	MPI_Comm_free(&newComm);
}

int main(int argc, char *argv[])
{
	MPI_Init(&argc, &argv);
	MPI_Status status;
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	vector<int> data;
	int n; 

	if (rank == 0)
	{
		// data generation at process 0
		ifstream fin("input.txt");
		if (!fin)
		{
			cerr << "Error opening file.\n";
			return 1;
		}

		fin >> n;
		data.resize(n);

		for (int i = 0; i < n; i++)
			fin >> data[i];
	}

	// Broadcasting number of elements to all processes
	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

	int part = n / size, rem = n % size;
	int sendCount = rank < rem ? part + 1 : part;
	int pivot = 0;

	vector<int> recvData(sendCount);
	vector<int> sendCounts;
	vector<int> sDisps;

	if(rank == 0) {
		sendCounts.resize(size);
		sDisps.resize(size);

		int offset = 0;
		for (int i = 0; i < size; i++)
		{
			sendCounts[i] = part + (i < rem ? 1 : 0);
			sDisps[i] = offset;
			offset += sendCounts[i];
		}
	}

	// sending data to all the other processes
	MPI_Scatterv(data.data(), sendCounts.data(), sDisps.data(), MPI_INT, recvData.data(), sendCount, MPI_INT, 0, MPI_COMM_WORLD);

	parallelQuickSort(recvData, MPI_COMM_WORLD);

	int localSize = recvData.size();
	vector<int> recvCounts, disps;
	if(rank == 0) {
		recvCounts.resize(size);
		disps.resize(size);
	}
	// count of localData to be stored at process 0
	MPI_Gather(&localSize, 1, MPI_INT, recvCounts.data(), 1, MPI_INT, 0, MPI_COMM_WORLD);

	if (rank == 0)
	{
		disps[0] = 0;
		for (int i = 1; i < size; i++)
			disps[i] = disps[i - 1] + recvCounts[i - 1];

		data.resize(disps[size - 1] + recvCounts[size - 1]);
	}

	// receiving the actual data
	MPI_Gatherv(recvData.data(), localSize, MPI_INT, data.data(), recvCounts.data(), disps.data(), MPI_INT, 0, MPI_COMM_WORLD);

	if (rank == 0)
	{
		ofstream fout("output.txt");
		cout << "Sorted Array: ";
		fout << "Sorted Array: " << endl;
		for (int n : data) {
			cout << n << " ";
			fout << n << " ";
		}
		cout << endl;
	}

	MPI_Finalize();
}
