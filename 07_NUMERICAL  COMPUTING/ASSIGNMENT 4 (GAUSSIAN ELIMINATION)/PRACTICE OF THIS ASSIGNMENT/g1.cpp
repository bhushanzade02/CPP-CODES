#include <iostream>
using namespace std;

void gaussianStep(double matrix[][4], int rows) {
    // Step 1: Normalize the first row
    double a11 = matrix[0][0];
    for (int j = 0; j < 4; j++) {  // Normalize first row
        matrix[0][j] /= a11;
    }

    // Step 2: Make first column zero below pivot
    for (int i = 1; i < rows; i++) {  // Start from row 2 (index 1)
        double factor = matrix[i][0]; // a_i1
        for (int j = 0; j < 4; j++) {
            matrix[i][j] -= factor * matrix[0][j]; // R_i = R_i - a_i1 * R_1
        }
    }

    // Print the matrix after this step
    cout << "Matrix after normalization and elimination:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    double matrix[3][4] = {
        {2, 3, 1, 1},
        {4, 7, 3, 3},
        {6, 18, 5, 5}
    };

    gaussianStep(matrix, 3);

    return 0;
}
