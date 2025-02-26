#include <iostream>
#include <vector>

using namespace std;

void processFirstRow(vector<vector<double>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

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

    // Print the updated matrix
    cout << "Matrix after first row processing:\n";
    for (const auto &row : matrix) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<double>> matrix = {
        {2, 3, 1, 1},
        {4, 7, 3, 3},
        {6, 18, 5, 5}
    };

    processFirstRow(matrix);

    return 0;
}
