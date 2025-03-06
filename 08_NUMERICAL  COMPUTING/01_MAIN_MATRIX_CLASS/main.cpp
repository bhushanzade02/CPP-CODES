#include "Matrix.hpp"

int main() {
    int r1, c1, r2, c2;
    cout << "Enter rows and columns for the first matrix: ";
    cin >> r1 >> c1;
    Matrix mat1(r1, c1);
    mat1.inputMatrix();

    cout << "Enter rows and columns for the second matrix: ";
    cin >> r2 >> c2;
    Matrix mat2(r2, c2);
    mat2.inputMatrix();

    if (r1 == r2 && c1 == c2) {
        Matrix sum = mat1.add(mat2);
        Matrix diff = mat1.sub(mat2);

        cout << "ADDITION:\n";
        sum.display();

        cout << "SUBTRACTION:\n";
        diff.display();
    } else {
        cout << "Matrices must have the same dimensions for addition/subtraction!\n";
    }

    if (r1 == c1) {
        cout << "\nDeterminant of first matrix: " << mat1.determinant() << endl;
        if (mat1.isIdentity()) {
            cout << "First matrix is an identity matrix!\n";
        } else {
            cout << "First matrix is NOT an identity matrix!\n";
        }
    }

    int n, m;
    cout << "\nEnter the number of rows and columns for augmented matrix: ";
    cin >> n >> m;

    if (m != n + 1) {
        cout << "Error: Augmented matrix should have (n x n+1) dimensions!\n";
        return 1;
    }

    Matrix augmentedMatrix(n, m);
    augmentedMatrix.inputMatrix();
    cout << "\nDeterminant of coefficient matrix: " << augmentedMatrix.determinant() << endl;

    augmentedMatrix.gaussianElimination();

    return 0;
}
