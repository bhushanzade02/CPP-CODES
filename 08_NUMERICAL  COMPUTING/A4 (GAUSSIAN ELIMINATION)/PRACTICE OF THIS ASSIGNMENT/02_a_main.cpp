#include <iostream>
#include <vector>

using namespace std;

// Function to perform Gaussian elimination
void gaussianElimination(vector<vector<double>> &matrix) {
    int n = matrix.size(); // Number of rows (assuming square matrix)

    for (int k = 0; k < n; k++) { // Process each row as pivot row
        // Step 1: Normalize the k-th row
        double pivot = matrix[k][k]; // Akk
        for (int j = 0; j < n; j++) {
            matrix[k][j] /= pivot;  // Normalize k-th row
        }

        // Step 2: Use row k to eliminate values in column k for rows i > k
        for (int i = k + 1; i < n; i++) { // Start from row (k+1)
            double factor = matrix[i][k]; // Aik
            for (int j = 0; j < n; j++) {
                matrix[i][j] -= factor * matrix[k][j]; // Ri = Ri - Aik * Rk
            }
        }
    }
}

int main() {
    vector<vector<double>> matrix = {
        {2, 1, -1},
        {-3, -1, 2},
        {-2, 1, 2}
    };

    cout << "Original Matrix:\n";
    for (const auto &row : matrix) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Perform Gaussian elimination
    gaussianElimination(matrix);

    cout << "\nMatrix after Gaussian Elimination:\n";
    for (const auto &row : matrix) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
