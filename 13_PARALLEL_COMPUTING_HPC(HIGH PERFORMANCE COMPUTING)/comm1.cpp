#include <mpi.h>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);
    MPI_Status status;
    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    cout << "From Process " << rank << " out of " << size << endl;
Government Institute of Science , Nagpur\
    int n = 100;
    int part = n / size;


    if(rank == 0) { 
    
        vector<int> A;
        for (int i = 1; i <=n; i++) A.push_back(i);


        MPI_Send(A.data()+part,part , MPI_INT , 1,1,MPI_COMM_WORLD);


            int lsum =0 ;
            for (int i =0 ; i < part ; i++)
            lsum += A[i];


        ////////////
        int sum ;
        MPI_Recv(&sum,1, MPI_INT , 1,2,MPI_COMM_WORLD,&status );
        int totalSum = lsum + sum ;
        cout <<"Total sum is "<< totalSum <<endl;
}
   if (rank != 0 )

   {
    vector<int>B(part);
    MPI_Recv(B.data(),part,MPI_INT , 0,1, MPI_COMM_WORLD ,&status );
    

    int lsum =0 ;
    for(int i =0 ; i < part ;i++) lsum +=B[i];


    MPI_Send(&lsum , 1 , MPI_INT ,0 ,2,MPI_COMM_WORLD);

   }

    MPI_Finalize();
}
