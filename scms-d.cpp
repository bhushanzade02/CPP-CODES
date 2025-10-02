#include<iostream>
#include<mpi.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{
        MPI_Init(&argc, &argv);
        MPI_Status status;
        int rank, size;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);

        int rows = 8, cols = 8, noRows = rows / size;
	int sendCount = noRows * cols;
        vector<int> data;
        vector<int> vec(cols);
        vector<int> row(sendCount);
        vector<int> ans(rows);
        if(rank == 0)
        { 
                // data generation at process 0
                data.resize(rows * cols);
                data = {1, 2, 3, 4, 5, 6, 7, 8, 2, 4, 6, 8, 10, 12, 14, 16, 3, 6, 9, 12, 15, 18, 21, 24, 4, 8, 12, 16, 20, 24, 28, 32, 5, 10, 15, 20, 25, 30, 35, 40, 6, 12, 18, 24, 30, 36, 42, 48, 7, 14, 21, 28, 35, 42, 49, 56, 8, 16, 24, 32, 40, 48, 56, 64};
                vec = {1, 1, 1, 1, 1, 1, 1, 1};
        }

        // sending data to all the other processes
        MPI_Scatter(data.data(), sendCount, MPI_INT, row.data(), sendCount, MPI_INT, 0, MPI_COMM_WORLD);

        // sending vector to all the processes
        MPI_Bcast(vec.data(), cols, MPI_INT, 0, MPI_COMM_WORLD);

        /*cout << endl; 
        cout << "Data Received at " << rank << ": " << endl;
        for(int i=0; i<sendCount; i++)
                cout << row[i] << " ";
        cout << endl;

        cout << endl;
        cout << "Vector X at " << rank << ": " << endl;
        for(int i=0; i<cols; i++)
                cout << vec[i] << " ";
        cout << endl;

	*/
       	// calculating the multiplication for each row independently
        vector<int> result(noRows);
        for(int i=0; i<noRows; i++)
        {
		int b = 0;
		for(int j=0; j<cols; j++)
                	b += row[j + (i*cols)] * vec[j];

		result[i] = b;
        }

	/*cout << endl;
        cout << "Result at " << rank << ": " << endl;
        for(int i=0; i<noRows; i++)
                cout << result[i] << " ";
        cout << endl;
	*/
	
        // element of ans vector b to be stored at process 0
        MPI_Gather(result.data(), noRows, MPI_INT, ans.data(), noRows, MPI_INT, 0, MPI_COMM_WORLD);

        if(rank == 0)
        {
                cout << endl;
                cout << "Vector b: " ;
                for(int n : ans)
                        cout << n << " ";
                cout << endl;
        }

        MPI_Finalize();
}
