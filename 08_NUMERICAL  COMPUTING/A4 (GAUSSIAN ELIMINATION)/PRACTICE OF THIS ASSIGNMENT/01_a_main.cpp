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



    // Step 1: Normalize the first row
    double pivot = matrix[0][0]; // a11
    for (int j = 0; j < cols; j++) {
        matrix[0][j] /= pivot;  // Normalize first row
    }

    // Step 2: Make first column below pivot zero
    for (int i = 1; i < rows; i++) {  // Start from row 2 (index 1)
        double factor = matrix[i][0]; // a_i1
        for (int j = 0; j < cols; j++) {
            matrix[i][j] -= factor * matrix[0][j]; // R_i = R_i - a_i1 * R_1
        }
    }



     // Step 1: Normalize the second row
     double pivot = matrix[1][1]; // A22
     for (int j = 0; j < cols; j++) {
         matrix[1][j] /= pivot;  // Normalize second row
     }
 
     // Step 2: Use row 2 to eliminate values in column 2 for other rows
     for (int i = 0; i < rows; i++) {
         if (i == 1) continue; // Skip row 2 (pivot row itself)
 
         double factor = matrix[i][1]; // A_i2
         for (int j = 0; j < cols; j++) {
             matrix[i][j] -= factor * matrix[1][j]; // R_i = R_i - A_i2 * R_2
         }
     }




// Step 1: Normalize the k-th row
double pivot = matrix[k][k]; // Akk
for (int j = 0; j < cols; j++) {
    matrix[k][j] /= pivot;  // Normalize k-th row
}

// Step 2: Use row k to eliminate values in column k for rows i >= k+1
for (int i = k + 1; i < rows; i++) { // Start from row (k+1)
    double factor = matrix[i][k]; // Aik
    for (int j = 0; j < cols; j++) {
        matrix[i][j] -= factor * matrix[k][j]; // Ri = Ri - Aik * Rk
    }
}


void processLastRow(vector<vector<double>> &matrix) {
    int n = matrix.size();  // Number of rows
    int cols = matrix[0].size();
    
    // Step: Normalize the last row (n-th row, index n-1)
    double pivot = matrix[n - 1][n - 1]; // Ann
    for (int j = 0; j < cols; j++) {
        matrix[n - 1][j] /= pivot;  // Rn = (1/Ann) * Rn
    }
}
