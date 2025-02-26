#include <iostream>
using namespace std;

// Function f(x)
double f(double x) {
    return x * x * x - x - 2; // Example: f(x) = x^3 - x - 2
}

int main() {
    double a, b, c;
    int maxIterations;

    // Input the interval and maximum iterations
    cout << "Enter interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter max iterations: ";
    cin >> maxIterations;

    // Check if root exists in the interval
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval. Root may not exist here.\n";
        return 1; // Exit the program
    }

    // Perform bisection
    for (int i = 0; i < maxIterations; i++) {
        c = (a + b) / 2; // Find midpoint

        if (f(c) == 0.0) { // Exact root found
            break;
        }

        if (f(a) * f(c) < 0) {
            b = c; // Root is in [a, c]
        } else {
            a = c; // Root is in [c, b]
        }
    }

    // Output result
    cout << "Approximate root: " << c << endl;
    return 0;
}
