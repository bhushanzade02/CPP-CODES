#include <iostream>
#include <vector>

using namespace std;

// Function prototype
void processFirstRow(vector<vector<double>> &matrix);

int main() {
    int rows = 3, cols = 3;
    
    // Declare matrix with type double
    vector<vector<double>> matrix(rows, vector<double>(cols));

    // Initialize matrix with values
    cout << "Original Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1; // Avoid division by zero
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Process the first row for Gaussian elimination
    processFirstRow(matrix);

    // Print the modified matrix
    cout << "\nMatrix after processing first row:\n";
    for (const auto &row : matrix) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

// Function to normalize the first row and eliminate first column below it
void processFirstRow(vector<vector<double>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Step 1: Normalize the first row
    double pivot = matrix[0][0]; // a11
    for (int j = 0; j < cols; j++) {
        matrix[0][j] /= pivot;  // Normalize first row
    }

    // Step 2: Make first column zero below pivot
    for (int i = 1; i < rows; i++) {  
        double factor = matrix[i][0]; // a_i1
        for (int j = 0; j < cols; j++) {
            matrix[i][j] -= factor * matrix[0][j]; // R_i = R_i - a_i1 * R_1
        }
    }
}
