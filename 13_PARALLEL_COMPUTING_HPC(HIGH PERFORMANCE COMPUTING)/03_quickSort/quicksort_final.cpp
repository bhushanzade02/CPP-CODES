#include <iostream>
#include <mpi.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Partition Function */
int Partition(vector<int> &A, int low, int high)
{
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (A[j] <= pivot)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[high]);
    return i + 1;
}

/* Quick Sort Function */
void quicksort(vector<int> &A, int low, int high)
{
    if (low < high)
    {
        int pi = Partition(A, low, high);
        quicksort(A, low, pi - 1);
        quicksort(A, pi + 1, high);
    }
}

/* Merge Two Sorted Vectors */
vector<int> MergeVector(const vector<int> &low, const vector<int> &high)
{
    vector<int> M;
    int i = 0, j = 0;
    while (i < low.size() && j < high.size())
    {
        if (low[i] <= high[j])
            M.push_back(low[i++]);
        else
            M.push_back(high[j++]);
    }
    while (i < low.size())
        M.push_back(low[i++]);
    while (j < high.size())
        M.push_back(high[j++]);
    return M;
}

/* Choose median as pivot */
int selectP(const vector<int> &A)
{
    if (A.empty())
        return 0; // edge case
    return A[A.size() / 2];
}

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int myrank, npes;
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &npes);

    vector<int> D;
    int totalelems = 0;

    // Step 1: Root prepares data
    if (myrank == 0)
    {
        cout << "Enter Number of elements: ";
        cin >> totalelems;
        D.resize(totalelems);
        cout << "Enter elements: ";
        for (int i = 0; i < totalelems; i++)
        {
            cin >> D[i];
        }
    }

    // Step 2: Broadcast total size
    MPI_Bcast(&totalelems, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Step 3: Scatter with uneven distribution
    vector<int> sc(npes, totalelems / npes);
    vector<int> displs(npes, 0);
    int rem = totalelems % npes;
    for (int i = 0; i < rem; i++)
        sc[i]++;
    for (int i = 1; i < npes; i++)
        displs[i] = displs[i - 1] + sc[i - 1];

    // Step 4: Local data buffer
    vector<int> LD(sc[myrank]);

    // Step 5: Scatterv
    MPI_Scatterv(D.data(), sc.data(), displs.data(), MPI_INT,
                 LD.data(), sc[myrank], MPI_INT, 0, MPI_COMM_WORLD);

    // Step 6: Local quicksort
    if (!LD.empty())
        quicksort(LD, 0, LD.size() - 1);

    // Step 7: Multi-step pivot exchange
    int step = 1;
    while (step < npes)
    {
        int lpivot = selectP(LD);
        int pivot;
        // Broadcast pivot from rank 0 of the group
        MPI_Bcast(&lpivot, 1, MPI_INT, 0, MPI_COMM_WORLD);
        pivot = lpivot;

        // Partition local data
        vector<int> lpart, upart;
        for (int val : LD)
        {
            if (val <= pivot)
                lpart.push_back(val);
            else
                upart.push_back(val);
        }

        // Determine partner
        int partner = (myrank / step % 2 == 0) ? myrank + step : myrank - step;

        if (partner < npes && partner >= 0)
        {
            int send_size = (myrank / step % 2 == 0) ? upart.size() : lpart.size();
            int recv_size;

            MPI_Sendrecv(&send_size, 1, MPI_INT, partner, 0,
                         &recv_size, 1, MPI_INT, partner, 0,
                         MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            vector<int> send_data = (myrank / step % 2 == 0) ? upart : lpart;
            vector<int> recv_data(recv_size);

            MPI_Sendrecv(send_data.data(), send_size, MPI_INT, partner, 1,
                         recv_data.data(), recv_size, MPI_INT, partner, 1,
                         MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            if (myrank / step % 2 == 0)
                LD = MergeVector(lpart, recv_data);
            else
                LD = MergeVector(recv_data, upart);
        }
        else
        {
            LD = (myrank / step % 2 == 0) ? lpart : upart;
        }

        step *= 2;
    }

    // Step 8: Final local sort
    if (!LD.empty())
        quicksort(LD, 0, LD.size() - 1);

    // Step 9: Gather results back
    vector<int> recvcount(npes), displs_gather(npes);
    int locsize = LD.size();
    MPI_Gather(&locsize, 1, MPI_INT, recvcount.data(), 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (myrank == 0)
    {
        displs_gather[0] = 0;
        for (int i = 1; i < npes; i++)
            displs_gather[i] = displs_gather[i - 1] + recvcount[i - 1];
        D.resize(totalelems);
    }

    MPI_Gatherv(LD.data(), locsize, MPI_INT,
                D.data(), recvcount.data(), displs_gather.data(), MPI_INT,
                0, MPI_COMM_WORLD);

    // Step 10: Print sorted result
    if (myrank == 0)
    {
        cout << "Sorted array: ";
        for (int val : D)
            cout << val << " ";
        cout << endl;
    }

    MPI_Finalize();
    return 0;
}
