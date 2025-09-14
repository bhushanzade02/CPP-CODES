// MS-2301-assgn3.cpp
// Parallel QuickSort with MPI

#include <mpi.h>
#include <iostream>
using namespace std;


int partition(int A[], int start, int end) {
    int pivot = A[start];
    int i = start;

    for (int j = start + 1; j <= end; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i], A[start]);
    return i;
}

void quicksort(int A[], int start, int end) {
    if (end - start <= 0) return;

    int index = partition(A, start, end);
    quicksort(A, start, index - 1);
    quicksort(A, index + 1, end);
}

int main(int argc, char *argv[]) {
    int rank, size, n;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int arr[100];
    int part, rem;

    if (rank == 0) {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter " << n << " elements:\n";
        for (int i = 0; i < n; i++)
            cin >> arr[i];


        for (int p = 1; p < size; p++) {
            MPI_Send(&n, 1, MPI_INT, p, 0, MPI_COMM_WORLD);
        }
    } else {
     
        MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    }

    part = n / size;
    rem  = n % size;

    if (rank == 0) {

        for (int p = 1; p < size; p++) {
            int cnt = (p < rem) ? (part + 1) : part;
            int start_idx = p * part + (p < rem ? p : rem);
            MPI_Send(&arr[start_idx], cnt, MPI_INT, p, 1, MPI_COMM_WORLD);
        }


        int cnt0 = (0 < rem) ? (part + 1) : part;
        quicksort(arr, 0, cnt0 - 1);

        for (int p = 1; p < size; p++) {
            int cnt = (p < rem) ? (part + 1) : part;
            int start_idx = p * part + (p < rem ? p : rem);
            MPI_Recv(&arr[start_idx], cnt, MPI_INT, p, 2, MPI_COMM_WORLD, &status);
        }

   
        quicksort(arr, 0, n - 1);

        cout << "Sorted array:\n";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    if (rank != 0) {
        int cnt = (rank < rem) ? (part + 1) : part;
        int buf[100];

        MPI_Recv(buf, cnt, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);

        quicksort(buf, 0, cnt - 1);

        MPI_Send(buf, cnt, MPI_INT, 0, 2, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
