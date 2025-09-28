#include<mpi.h>
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main(int argc , char *argv[])
{
    MPI_Init(&argc , &argv);
    int npes , myrank ;
    MPI_Comm_size(MPI_COMM_WORLD , &npes);
    MPI_Comm_rank(MPI_COMM_WORLD , &myrank);


    cout << "from processor " << myrank << "out off" << npes << endl ;


    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    cout << n << endl;

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;


    MPI_Finalize();
}
