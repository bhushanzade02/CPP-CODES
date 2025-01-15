#include <iostream>
using namespace std;

// Function to evaluate f(x)
double f(double x) {
    return 2*x*x-1; // Cubic function
}

int main() {
    double a, b, c;
    int iteration;

    // Input the interval and number of iterations
    cout << "Enter interval values a and b: ";
    cin >> a >> b;
    cout << "Enter the number of iterations: ";
    cin >> iteration;

    // Check if the interval is valid
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval it must have opposite symbol." << endl;
        return 1;
    }

    // Perform the bisection method
    for (int i = 0; i < iteration; i++) {
        c = (a + b) / 2; // Calculate midpoint

        if (f(c) == 0.0) { // Exact root found
            break;
        }

        // Update the interval
        if (f(a) * f(c) < 0) {
            b = c; // Root is in [a, c]
        } else {
            a = c; // Root is in [c, b]
        }
    }

    // Output the result
    cout << "Root is approximately: " << c << endl;

    return 0;
}

