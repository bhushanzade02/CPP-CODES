#include "RootFinding.hpp"

using namespace std;

//  f(x) for bisection 
double RootFinding::function(double x) {
    return x * x * x - x - 2;  
}

// Derivativ  Newton-Raphson
double RootFinding::derivative(double x) {
    return 3 * x * x - 1;  
}

// Fixed Point Iteration function after transforming this 
double RootFinding::g(double x) {
    return (2 + x) / 3;  // x = (2 + x) / 3
}

// Bisection Method
void RootFinding::bisection(double a, double b, double tol) {
    if (function(a) * function(b) >= 0) {
        cout << "f(a) and f(b) have opposite signass .\n";
        return;
    }

    double mid;
    int iter = 0;

    while ((b - a) >= tol) {
        mid = (a + b) / 2.0;
        cout << "Iteration " << iter++ << ": mid = " << mid << ", f(mid) = " << function(mid) << endl;

        if (function(mid) == 0.0) break;
        else if (function(mid) * function(a) < 0) b = mid;
        else a = mid;
    }

    cout << "Approximate root Bisection: " << mid << endl;
}

// Newton-Raphson Method
void RootFinding::newtonRaphson(double x0, double tol, int maxIter) {
    double x = x0;
    int iter = 0;

    while (iter < maxIter) {
        double fx = function(x);
        double dfx = derivative(x);

        if (dfx == 0) {
            cout << "Newton-Raphson method not execute because of derivate is zero .\n";
            return;
        }

        double x_next = x - fx / dfx;
        cout << "Iteration " << iter << ": x = " << x << ", f(x) = " << fx << endl;

        if (fabs(x_next - x) < tol) {
            cout << "Root found (Newton-Raphson): " << x_next << endl;
            return;
        }

        x = x_next;
        iter++;
    }

    cout << "Approximate root Newton-Raphson: " << x << endl;
}

// Fixed-Point Iteration Method
void RootFinding::fixedPointIteration(double x0, double tol, int maxIter) {
    double x = x0;
    int iter = 0;

    while (iter < maxIter) {
        double x_next = g(x);
        cout << "Iteration " << iter << ": x = " << x << endl;

        if (fabs(x_next - x) < tol) {
            cout << "Root found Fixed-Point Iteration: " << x_next << endl;
            return;
        }

        x = x_next;
        iter++;
    }

    cout << " Approximate root Fixed-Point: " << x << endl;
}
