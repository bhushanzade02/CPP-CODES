#include<iostream>
#include<vector>
using namespace std;

int main()
{
   
    int rows= 3;
    int cols=3;
    vector<vector<int>> matrix(rows, vector<int >(cols));


    for(int i=0; i<rows;i++)
    {
        for(int j=0; j<cols;j++)
        {
            matrix[i][j]=i*cols+j;
            cout<<matrix[i][j]<<" "; 
        }
        cout<<endl;
    }

return 0;

}