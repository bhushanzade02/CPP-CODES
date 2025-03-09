#include "GaussianElimination.hpp"

// Constructor to initialize the matrix
GaussianElimination::GaussianElimination(vector<vector<double>> mat) {
    matrix = mat;
    n = matrix.size();
}

// Function to perform Gaussian elimination
void GaussianElimination::eliminate() {
    for (int k = 0; k < n; k++) { // Pivot row
        // Step 1: Normalize the k-th row
        double pivot = matrix[k][k];
        for (int j = 0; j < n; j++) {
            matrix[k][j] /= pivot; // Normalize k-th row
        }

        // Step 2: Use row k to eliminate values in column k for rows i > k
        for (int i = k + 1; i < n; i++) { // Start from row (k+1)
            double factor = matrix[i][k];
            for (int j = 0; j < n; j++) {
                matrix[i][j] -= factor * matrix[k][j]; // Ri = Ri - Aik * Rk
            }
        }
    }
}

// Function to display the matrix
void GaussianElimination::display() {
    for (const auto &row : matrix) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
