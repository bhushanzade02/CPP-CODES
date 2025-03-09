#include"Matrix.hpp"

// Constructor
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data.resize(rows, vector<double>(cols, 0));
    if (cols == rows + 1) {
        solution.resize(rows, 0);
    }
}

// User input
void Matrix::inputMatrix() {
    cout << "Enter matrix elements (" << rows << "x" << cols << "):\n";
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
        cout << "Matrix dimesion is check";
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
        cout << "Matrix dimesion check";
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

// detreminant
double Matrix::determinant() const {
    if (rows != cols) {
        cout << "matrix is size is not ";
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
    cout << "ENTERED matrix:\n";
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

    cout << "matrix after gauss :\n";
    display();
    backSubstitution();
}

// Back-Substitution
void Matrix::backSubstitution() {
    cout << " back substitution " ;

    for (int i = rows - 1; i >= 0; i--) {
        solution[i] = data[i][cols - 1];
        for (int j = i + 1; j < rows; j++) {
            solution[i] -= data[i][j] * solution[j];
        }
    }

    cout << "solution:\n";
    for (int i = 0; i < rows; i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
}

