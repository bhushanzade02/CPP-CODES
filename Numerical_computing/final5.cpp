#include <iostream>
#include <cmath>  // For fabs() and pow()
using namespace std;

double fun(double x)
{
    return  x * x *x - x - 2;  // Example: f(x) = x^3 - 2x - 2
}

int main()
{
    double a = 1, b = 2, c, eps = 0.001;
    int count = 1;  // Initialize iteration count

    // Check if the function values at a and b have opposite signs
    if (fun(a) * fun(b) >= 0) {
        cout << "The initial interval does not contain a root." << endl;
        return 1;  // Exit if no root is expected in the interval
    }

    // Bisection method
    while (fabs(b - a) > eps)  // Loop until the interval is sufficiently small
    {
        c = (a + b) / 2;  // Midpoint of the interval

        // Check if root is found or update the interval
        if (fun(c) == 0) {
            cout << "Exact root is " << c << endl;
            break;
        }

        if (fun(a) * fun(c) < 0) {
            b = c;  // Root lies between a and c
        } else {
            a = c;  // Root lies between c and b
        }

        cout << "Iteration " << count++ << endl;
        cout << "Value of c: " << c << endl;
    }

    // Final approximation
    cout << "Approximate root after " << count - 1 << " iterations: " << c << endl;
    return 0;
}
