#include "RootFinding.hpp"
#include <iostream>

using namespace std;

int main()
{
    RootFinding numericalcomp;
    double a = 1, b = 2, x0 = 1.5;
    double tol = 0.0001;
    int maxIter = 100;

    cout << " Bisection Method ";
    numericalcomp.bisection(a, b);

    cout << "  Newton-Raphson Method ";
    numericalcomp.newtonRaphson(x0, maxIter);

    cout << " Fixed-Point Iteration ";
    numericalcomp.fixedPointIteration(x0, tol, maxIter);

    return 0;
}
