#include "GaussianElimination.hpp"

using namespace std;

int main() {
    int n;

    // Taking matrix size from user
    cout << "Enter the number of variables (n): ";
    cin >> n;

    // Declare augmented matrix
    vector<vector<double>> mat(n, vector<double>(n + 1));

    // Taking matrix elements from user
    cout << "Enter the augmented matrix (coefficients + constants):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cin >> mat[i][j];
        }
    }

    // Create an object of GaussianElimination
    GaussianElimination solver(mat);

    cout << "\nOriginal Augmented Matrix:\n";
    solver.display();

    // Perform Gaussian elimination (Forward Elimination)
    solver.eliminate();

    cout << "\nMatrix after Gaussian Elimination:\n";
    solver.display();

    // Perform Back-Substitution
    solver.backSubstitution();

    // Display the solution
    solver.displaySolution();

    return 0;
}
