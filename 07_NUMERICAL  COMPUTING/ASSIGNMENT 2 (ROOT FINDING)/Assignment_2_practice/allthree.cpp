#include <iostream>
#include <cmath>

using namespace std;

class RootFinding {
private:
    // Function f(x) whose root we want to find
    double function(double x) {
        return x * x * x - x - 2;  // Example: f(x) = x^3 - x - 2
    }

    // Derivative of f(x) for Newton-Raphson
    double derivative(double x) {
        return 3 * x * x - 1;  // f'(x) = 3x^2 - 1
    }

    // Fixed-Point Iteration function g(x)
    double g(double x) {
        return (2 + x) / 3;  // Example transformation: x = (2 + x) / 3
    }

public:
    // Bisection Method
    void bisection(double a, double b, double tol) {
        if (function(a) * function(b) >= 0) {
            cout << "Invalid interval. f(a) and f(b) must have opposite signs.\n";
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

        cout << "Approximate root (Bisection): " << mid << endl;
    }

    // Newton-Raphson Method
    void newtonRaphson(double x0, double tol, int maxIter) {
        double x = x0;
        int iter = 0;

        while (iter < maxIter) {
            double fx = function(x);
            double dfx = derivative(x);

            if (dfx == 0) {
                cout << "Derivative is zero. Newton-Raphson method fails.\n";
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

        cout << "Max iterations reached. Approximate root (Newton-Raphson): " << x << endl;
    }

    // Fixed-Point Iteration Method
    void fixedPointIteration(double x0, double tol, int maxIter) {
        double x = x0;
        int iter = 0;

        while (iter < maxIter) {
            double x_next = g(x);
            cout << "Iteration " << iter << ": x = " << x << endl;

            if (fabs(x_next - x) < tol) {
                cout << "Root found (Fixed-Point Iteration): " << x_next << endl;
                return;
            }

            x = x_next;
            iter++;
        }

        cout << "Max iterations reached. Approximate root (Fixed-Point): " << x << endl;
    }
};

int main() {
    RootFinding solver;
    double a = 1, b = 2, x0 = 1.5;
    double tol = 0.0001;
    int maxIter = 100;

    cout << "\n--- Bisection Method ---\n";
    solver.bisection(a, b, tol);

    cout << "\n--- Newton-Raphson Method ---\n";
    solver.newtonRaphson(x0, tol, maxIter);

    cout << "\n--- Fixed-Point Iteration ---\n";
    solver.fixedPointIteration(x0, tol, maxIter);

    return 0;
}
