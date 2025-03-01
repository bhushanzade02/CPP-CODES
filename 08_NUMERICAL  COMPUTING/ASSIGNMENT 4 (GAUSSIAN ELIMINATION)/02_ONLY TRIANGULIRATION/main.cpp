#include "GaussianElimination.hpp"
using namespace std;

int main() {
    int n;

    // Taking matrix size from user
    cout << "Enter the size of the square matrix (n x n): ";
    cin >> n;

    // Declare matrix with user input
    vector<vector<double>> mat(n, vector<double>(n));

    // Taking matrix elements from user
    cout << "Enter the matrix elements row by row:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> mat[i][j];
        }
    }

    // Create an object of GaussianElimination
    GaussianElimination solver(mat);

    cout << "Original Matrix:\n";
    solver.display();

    // Perform Gaussian elimination
    solver.eliminate();

    cout << "\nMatrix after Gaussian Elimination:\n";
    solver.display();

    return 0;
}
