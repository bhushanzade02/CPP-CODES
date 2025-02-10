#include <iostream>
#include <cmath>

using namespace std;

// Define the function f(x)
double f(double x) {
    return x * x * x - x - 2;  // Example: f(x) = x^3 - x - 2
}

// Define the derivative f'(x)
double df(double x) {
    return 3 * x * x - 1;  // Derivative: f'(x) = 3x^2 - 1
}

// Newton-Raphson Method
void newtonRaphson(double x0, double tol, int maxIter) {
    double x = x0;  // Initial guess
    int iter = 0;

    while (iter < maxIter) {
        double fx = f(x);
        double dfx = df(x);

        if (dfx == 0) {  // Avoid division by zero
            cout << "Derivative is zero. Newton-Raphson method fails." << endl;
            return;
        }

        double x_next = x - fx / dfx;  // Newton-Raphson formula

        cout << "Iteration " << iter << ": x = " << x << ", f(x) = " << fx << endl;

        if (fabs(x_next - x) < tol) {  // Check convergence
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

    newtonRaphson(initialGuess, tolerance, maxIterations);

    return 0;
}
