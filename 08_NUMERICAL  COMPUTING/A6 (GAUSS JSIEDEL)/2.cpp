#include<iostream>
#include<cmath>
using namespace std;

void swapRows(double A[][10], int row1, int row2, int n) {
    for (int j = 0; j < n; j++) {
        double temp = A[row1][j];   // Store the value of row1 in temp
        A[row1][j] = A[row2][j];   // Copy row2 value to row1
        A[row2][j] = temp;         // Put temp value into row2
    }
}




void makeDiagonallyDominant(double A[][10], int n) {
    for (int i = 0; i < n; i++) {   // Loop over each row
        int bigRow = i;  // Assume the biggest number is in the current row

        for (int j = i + 1; j < n; j++) {  // Check all rows below
            if (fabs(A[j][i]) > fabs(A[bigRow][i])) {  // Find the row with the biggest value in column i
                bigRow = j;
            }
        }

        if (bigRow != i) { // If the biggest value is in another row, swap them
            swapRows(A, i, bigRow, n);
        }
    }
}


int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;

    double A[10][10];  // Matrix A

    cout << "Enter matrix values row by row:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];  // Read values
        }
    }

    makeDiagonallyDominant(A, n);  // Call function to swap rows if needed
    printMatrix(A, n);  // Print the new matrix

    return 0;
}
