#include "Matrix.hpp"

// Constructor
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data.resize(rows, vector<double>(cols, 0));
    if (cols == rows + 1) {
        solution.resize(rows, 0);
    }
}

// User input
void Matrix::inputMatrix() {
    cout << "Enter matrix elements row-wise (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> data[i][j];
}

// Display matrix
void Matrix::display() const {
    for (const auto &row : data) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Matrix addition
Matrix Matrix::add(const Matrix &other) const {
    if (rows != other.rows || cols != other.cols) {
        cout << "Matrix dimensions must match for addition!\n";
        return *this;
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

// Matrix subtraction
Matrix Matrix::sub(const Matrix &other) const {
    if (rows != other.rows || cols != other.cols) {
        cout << "Matrix dimensions must match for subtraction!\n";
        return *this;
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] - other.data[i][j];
    return result;
}

// Check if matrix is identity
bool Matrix::isIdentity() const {
    if (rows != cols) return false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i == j && data[i][j] != 1) || (i != j && data[i][j] != 0))
                return false;
        }
    }
    return true;
}

// Compute determinant (Recursive function)
double Matrix::determinant() const {
    if (rows != cols) {
        cout << "Determinant is only defined for square matrices!\n";
        return 0;
    }
    if (rows == 1) return data[0][0];
    if (rows == 2) return data[0][0] * data[1][1] - data[0][1] * data[1][0];

    double det = 0;
    for (int k = 0; k < cols; k++) {
        Matrix subMatrix(rows - 1, cols - 1);
        for (int i = 1; i < rows; i++) {
            int colIndex = 0;
            for (int j = 0; j < cols; j++) {
                if (j == k) continue;
                subMatrix.data[i - 1][colIndex++] = data[i][j];
            }
        }
        det += (k % 2 == 0 ? 1 : -1) * data[0][k] * subMatrix.determinant();
    }
    return det;
}

// Gaussian Elimination
void Matrix::gaussianElimination() {
    cout << "\nMatrix before Gaussian Elimination:\n";
    display();

    for (int k = 0; k < rows; k++) {
        double pivot = data[k][k];
        for (int j = k; j < cols; j++) {
            data[k][j] /= pivot;
        }
        for (int i = k + 1; i < rows; i++) {
            double factor = data[i][k];
            for (int j = k; j < cols; j++) {
                data[i][j] -= factor * data[k][j];
            }
        }
    }

    cout << "\nMatrix after Gaussian Elimination:\n";
    display();
    backSubstitution();
}

// Back-Substitution
void Matrix::backSubstitution() {
    cout << "\nPerforming Back-Substitution...\n";

    for (int i = rows - 1; i >= 0; i--) {
        solution[i] = data[i][cols - 1];
        for (int j = i + 1; j < rows; j++) {
            solution[i] -= data[i][j] * solution[j];
        }
    }

    cout << "\nSolution:\n";
    for (int i = 0; i < rows; i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
}

// Setter function
void Matrix::setValue(int row, int col, double val) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        data[row][col] = val;
    } else {
        cout << "Invalid index!" << endl;
    }
}
