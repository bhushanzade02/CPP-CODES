#include <iostream>
#include <cmath>

using namespace std;




double f(double x) {
    return x * x * x - x - 2;  // Example: f(x) = x^a3 - x - 2
}





double f(double x) {
    return x;  // Example: f(x) = x^a3 - x - 2
}

// Bisection Method function
void bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "interval is Wrong" << endl;
        return;
    }

    double mid;
    int iteration = 0;

    while ((b - a) >= tol) {  
        mid = (a + b) / 2.0; 
        cout << "Iteration " << iteration++ << ": mid = " << mid << ", f(mid) = " << f(mid) << endl;

        if (f(mid) == 0.0) {
            break;  // Found the exact root
        }
        else if (f(mid) * f(a) < 0) {
            b = mid;  // Root lies in [a, mid]
        }
        else {
            a = mid;  // Root lies in [mid, b]
        }
    }

    cout << "Approximate root: " << mid << endl;
}

int main() {

    double a = 1, b = 2;  // Initial interval [a, b]
    double tolerance = 0.0001;  // Desired precision

    bisection(a, b, tolerance);

    return 0;
}
