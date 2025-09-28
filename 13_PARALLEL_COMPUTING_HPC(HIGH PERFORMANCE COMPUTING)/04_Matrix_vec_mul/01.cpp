
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
	
	int rows = 4, cols = 4;
	vector<int> data;
	vector<int> vec(cols);
	vector<int> row(cols);
	vector<int> ans(rows);
	if(rank == 0)
        {
                // data generation at process 0
                data.resize(rows * cols);
                data = {1, 2, 3, 4, 2, 4, 6, 8, 3, 6, 9, 12, 4, 8, 12, 16};
                vec = {10, 11, 12, 13};
        }

	// sending data to all the other processes
	MPI_Scatter(data.data(), cols, MPI_INT, row.data(), cols, MPI_INT, 0, MPI_COMM_WORLD);
	
	// sending vector to all the processes
	MPI_Bcast(vec.data(), cols, MPI_INT, 0, MPI_COMM_WORLD);

	/*cout << endl; 
	cout << "Data Received at " << rank << ": " << endl;
	for(int i=0; i<cols; i++)
       		cout << row[i] << " ";
       	cout << endl;

	cout << endl;
        cout << "Vector X at " << rank << ": " << endl;
        for(int i=0; i<cols; i++)
                cout << vec[i] << " ";
        cout << endl;*/


	// calculating the multiplication for each row independently
	int b = 0;
	for(int i=0; i<cols; i++)
	{
		b += row[i] * vec[i];
	}
	cout << "B at " << rank << " is : " << b << endl;

	// element of ans vector b to be stored at process 0 
	MPI_Gather(&b, 1, MPI_INT, ans.data(), 1, MPI_INT, 0, MPI_COMM_WORLD);

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