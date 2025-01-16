#include <iostream>
using namespace std;

// Function f(x)
double f(double x) {
    return x * x - x - 2; // f(x) = x^2 - x - 2
}

int main() {
    double a, b, c;
    double tolerance = 1e-6;  // Tolerance to stop when the interval is small enough

    // Input the interval
    cout << "Enter interval [a, b]: ";
    cin >> a >> b;

    // Check if root exists in the interval
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval. Root may not exist here.\n";
        return 1; // Exit the program
    }

    // Perform bisection
    while ((b - a) / 2 > tolerance) {  // Loop until the interval is sufficiently small
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
