#include <iostream>
#include <cmath>

using namespace std;

// Define the function g(x) for fixed-point iteration
double g(double x) {
    return (2 + x) / 3;  // Example: g(x) = (2 + x) / 3 derived from x^3 - x - 2 = 0
}

// Fixed-Point Iteration Method
void fixedPointIteration(double x0, double tol, int maxIter) {
    double x = x0;  // Initial guess
    int iter = 0;

    while (iter < maxIter) {
        double x_next = g(x);  // Compute next iteration

        cout << "Iteration " << iter << ": x = " << x << endl;

        // Check convergence |x_next - x| < tolerance
        if (fabs(x_next - x) < tol) {
            cout << "Root found: " << x_next << endl;
            return;
        }

        x = x_next;  // Update x for next iteration
        iter++;
    }

    cout << "Maximum iterations reached. Approximate root: " << x << endl;
}

int main() {
    double initialGuess = 1.5;  // Starting value
    double tolerance = 0.0001;  // Desired precision
    int maxIterations = 100;  // Maximum number of iterations

    fixedPointIteration(initialGuess, tolerance, maxIterations);

    return 0;
}
