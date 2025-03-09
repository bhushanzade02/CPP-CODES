#include "GaussianElimination.hpp"

using namespace std;

// Constructor to initialize the matrix
GaussianElimination::GaussianElimination(vector<vector<double>> mat) {
    matrix = mat;
    n = matrix.size();
    solution.resize(n); // Initialize solution vector with size n
}

// Function to perform Gaussian elimination (Forward Elimination)
void GaussianElimination::eliminate() {
    for (int k = 0; k < n; k++) { // Pivot row
        // Step 1: Normalize the k-th row
        double pivot = matrix[k][k];
        for (int j = k; j < n + 1; j++) { // Include augmented column
            matrix[k][j] /= pivot; // Normalize k-th row
        }

        // Step 2: Use row k to eliminate values in column k for rows i > k
        for (int i = k + 1; i < n; i++) { // Start from row (k+1)
            double factor = matrix[i][k];
            for (int j = k; j < n + 1; j++) {
                matrix[i][j] -= factor * matrix[k][j]; // Ri = Ri - Aik * Rk
            }
        }
    }
}

// Function to perform Back-Substitution
void GaussianElimination::backSubstitution() {
    for (int i = n - 1; i >= 0; i--) { // Start from the last row
        solution[i] = matrix[i][n]; // Start with the rightmost column value (b_i)

        // Subtract known values from already computed solutions
        for (int j = i + 1; j < n; j++) {
            solution[i] -= matrix[i][j] * solution[j];
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

// Function to display the computed solution vector
void GaussianElimination::displaySolution() {
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
}
