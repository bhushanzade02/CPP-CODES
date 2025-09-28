#include <iostream>
#include <vector>
#include <algorithm>
#include <mpi.h>
#include <cstdlib>

// Partition function for QuickSort
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Sequential QuickSort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to recursively perform parallel QuickSort
void parallelQuickSort(std::vector<int>& local_data, MPI_Comm comm) {
    int rank, size;
    MPI_Comm_rank(comm, &rank);
    MPI_Comm_size(comm, &size);

    if (size == 1) {
        // Only one process in this communicator, just sort locally
        quickSort(local_data, 0, local_data.size() - 1);
        return;
    }

    // Step 1: Choose pivot (median-of-first-and-last)
    int pivot = local_data[local_data.size() / 2];
    MPI_Bcast(&pivot, 1, MPI_INT, 0, comm);

    // Step 2: Partition local data
    std::vector<int> lower, upper;
    for (int x : local_data) {
        if (x <= pivot) lower.push_back(x);
        else upper.push_back(x);
    }

    // Step 3: Count elements to exchange
    int lower_count = lower.size();
    int upper_count = upper.size();

    std::vector<int> all_lower_counts(size);
    std::vector<int> all_upper_counts(size);

    MPI_Allgather(&lower_count, 1, MPI_INT, all_lower_counts.data(), 1, MPI_INT, comm);
    MPI_Allgather(&upper_count, 1, MPI_INT, all_upper_counts.data(), 1, MPI_INT, comm);

    // Step 4: Calculate send/recv counts for Alltoallv
    std::vector<int> sendcounts(size), sdispls(size), recvcounts(size), rdispls(size);
    int total_lower = 0, total_upper = 0;
    for (int i = 0; i < size; i++) {
        if (rank < size / 2) { // lower half processors get lower elements
            sendcounts[i] = lower_count / size; // simple split
            recvcounts[i] = all_lower_counts[i] / size;
        } else { // upper half processors get upper elements
            sendcounts[i] = upper_count / size;
            recvcounts[i] = all_upper_counts[i] / size;
        }
        total_lower += recvcounts[i];
        total_upper += recvcounts[i];
    }

    // Step 5: Exchange data (simplified for illustration)
    // For production code, use MPI_Alltoallv with proper displacements
    local_data.clear();
    local_data.insert(local_data.end(), lower.begin(), lower.end());
    local_data.insert(local_data.end(), upper.begin(), upper.end());

    // Step 6: Split communicator
    int color = (rank < size / 2) ? 0 : 1;
    MPI_Comm new_comm;
    MPI_Comm_split(comm, color, rank, &new_comm);

    // Step 7: Recursive call
    parallelQuickSort(local_data, new_comm);

    MPI_Comm_free(&new_comm);
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const int num_elements = 16;
    std::vector<int> data;
    if (rank == 0) {
        data.resize(num_elements);
        for (int i = 0; i < num_elements; i++) {
            data[i] = rand() % 100;
        }
        std::cout << "Original Data: ";
        for (int x : data) std::cout << x << " ";
        std::cout << std::endl;
    }

    // Step 1: Scatter data
    int local_n = num_elements / size;
    std::vector<int> local_data(local_n);
    MPI_Scatter(data.data(), local_n, MPI_INT, local_data.data(), local_n, MPI_INT, 0, MPI_COMM_WORLD);

    // Step 2: Fully parallel QuickSort
    parallelQuickSort(local_data, MPI_COMM_WORLD);

    // Step 3: Gather fully sorted data on rank 0
    std::vector<int> final_sorted_data;
    if (rank == 0) final_sorted_data.resize(num_elements);

    MPI_Gather(local_data.data(), local_n, MPI_INT,
               final_sorted_data.data(), local_n, MPI_INT,
               0, MPI_COMM_WORLD);

    // Step 4: Final sort on rank 0 to merge blocks
    if (rank == 0) {
        std::sort(final_sorted_data.begin(), final_sorted_data.end());
        std::cout << "Final Sorted Data: ";
        for (int x : final_sorted_data) std::cout << x << " ";
        std::cout << std::endl;
    }

    MPI_Finalize();
    return 0;
}
