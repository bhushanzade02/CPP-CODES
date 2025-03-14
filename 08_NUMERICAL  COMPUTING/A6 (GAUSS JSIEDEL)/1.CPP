#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n; // Number of equations

    cout << "Enter the number of equations: ";
    cin >> n;

    double A[n][n], b[n], x_old[n], x_new[n];

    // Get matrix A and vector b from user
    cout << "Enter the coefficients of the matrix A (row-wise):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter the values of vector b:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // Initialize x_old to zeros
    for (int i = 0; i < n; i++) {
        x_old[i] = 0;
    }

    int max_iterations = 100;
    double tolerance = 0.000001;
    double error;

    cout << "Solving using Gauss-Jacobi method...\n";

    // Iteration loop
    for (int iter = 0; iter < max_iterations; iter++) {
        cout << "Iteration " << iter + 1 << ": ";

        // Compute new values for x
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (j != i) { // Skip diagonal elements
                    sum += A[i][j] * x_old[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }

        // Print values after each iteration
        for (int i = 0; i < n; i++) {
            cout << x_new[i] << " ";
        }
        cout << endl;

        // Check convergence
        error = 0;
        for (int i = 0; i < n; i++) {
            error += fabs(x_new[i] - x_old[i]); // Calculate difference
            x_old[i] = x_new[i]; // Update x_old for next iteration
        }

        if (error < tolerance) { // Stop if change is small
            break;
        }
    }

    // Print final solution
    cout << "Final solution: ";
    for (int i = 0; i < n; i++) {
        cout << x_new[i] << " ";
    }
    cout << endl;

    return 0;
}
