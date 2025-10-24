#include <mpi.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform partition in quicksort
int doPartition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int idx = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            idx++;
            swap(arr[idx], arr[j]);
        }
    }
    swap(arr[idx + 1], arr[high]);
    return idx + 1;
}

// Sequential quicksort
void quickSortSeq(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIdx = doPartition(arr, low, high);
        quickSortSeq(arr, low, pivotIdx - 1);
        quickSortSeq(arr, pivotIdx + 1, high);
    }
}

// Recursive parallel quicksort
void quickSortParallel(vector<int> &chunk, MPI_Comm comm)
{
    int rank, totalProcs;
    MPI_Comm_rank(comm, &rank);
    MPI_Comm_size(comm, &totalProcs);

    if (totalProcs == 1)
    {
        quickSortSeq(chunk, 0, chunk.size() - 1);
        return;
    }

    int pivotVal = 0;
    if (rank == 0)
        pivotVal = (!chunk.empty()) ? chunk.back() : 0;

    MPI_Bcast(&pivotVal, 1, MPI_INT, 0, comm);

    vector<int> leftPart, rightPart;
    for (int val : chunk)
    {
        if (val < pivotVal)
            leftPart.push_back(val);
        else
            rightPart.push_back(val);
    }

    vector<int> receivedData;
    int half = totalProcs / 2;
    int peer;

    if (rank < half)
    {
        peer = rank + half;

        int sendSz = rightPart.size(), recvSz;
        MPI_Sendrecv(&sendSz, 1, MPI_INT, peer, 0,
                     &recvSz, 1, MPI_INT, peer, 0, comm, MPI_STATUS_IGNORE);

        receivedData.resize(recvSz);
        MPI_Sendrecv(rightPart.data(), sendSz, MPI_INT, peer, 1,
                     receivedData.data(), recvSz, MPI_INT, peer, 1,
                     comm, MPI_STATUS_IGNORE);

        chunk = leftPart;
        chunk.insert(chunk.end(), receivedData.begin(), receivedData.end());
    }
    else
    {
        peer = rank - half;

        int sendSz = leftPart.size(), recvSz;
        MPI_Sendrecv(&sendSz, 1, MPI_INT, peer, 0,
                     &recvSz, 1, MPI_INT, peer, 0, comm, MPI_STATUS_IGNORE);

        receivedData.resize(recvSz);
        MPI_Sendrecv(leftPart.data(), sendSz, MPI_INT, peer, 1,
                     receivedData.data(), recvSz, MPI_INT, peer, 1,
                     comm, MPI_STATUS_IGNORE);

        chunk = rightPart;
        chunk.insert(chunk.end(), receivedData.begin(), receivedData.end());
    }

    int color = (rank < half) ? 0 : 1;
    MPI_Comm newComm;
    MPI_Comm_split(comm, color, rank, &newComm);

    quickSortParallel(chunk, newComm);
    MPI_Comm_free(&newComm);
}

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int rank, total;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &total);

    vector<int> allData;
    int nElements = 0;

    if (rank == 0)
    {
        ifstream fin("input.txt");
        if (!fin.is_open())
        {
            cerr << "Error: Unable to open input file.\n";
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        fin >> nElements;
        allData.resize(nElements);
        for (int i = 0; i < nElements; i++)
            fin >> allData[i];
        fin.close();
    }

    MPI_Bcast(&nElements, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int base = nElements / total;
    int remainder = nElements % total;
    int localCount = (rank < remainder) ? base + 1 : base;

    vector<int> recvChunk(localCount);
    vector<int> sendCounts, sendOffsets;

    if (rank == 0)
    {
        sendCounts.resize(total);
        sendOffsets.resize(total);

        int offset = 0;
        for (int i = 0; i < total; i++)
        {
            sendCounts[i] = base + (i < remainder ? 1 : 0);
            sendOffsets[i] = offset;
            offset += sendCounts[i];
        }
    }

    MPI_Scatterv(allData.data(), sendCounts.data(), sendOffsets.data(),
                 MPI_INT, recvChunk.data(), localCount, MPI_INT, 0, MPI_COMM_WORLD);

    quickSortParallel(recvChunk, MPI_COMM_WORLD);

    int localSize = recvChunk.size();
    vector<int> recvSizes, displacements;
    if (rank == 0)
    {
        recvSizes.resize(total);
        displacements.resize(total);
    }

    MPI_Gather(&localSize, 1, MPI_INT,
               recvSizes.data(), 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        displacements[0] = 0;
        for (int i = 1; i < total; i++)
            displacements[i] = displacements[i - 1] + recvSizes[i - 1];

        allData.resize(displacements[total - 1] + recvSizes[total - 1]);
    }

    MPI_Gatherv(recvChunk.data(), localSize, MPI_INT,
                allData.data(), recvSizes.data(), displacements.data(),
                MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        ofstream fout("output.txt");
        cout << "Sorted Output: ";
        fout << "Sorted Output:\n";

        for (int val : allData)
        {
            cout << val << " ";
            fout << val << " ";
        }
        cout << endl;
        fout.close();
    }

    MPI_Finalize();
    return 0;
}
