

#include <iostream>
#include <cmath>

class RootFinding {
private:
    double function(double x);      // f(x)
    double derivative(double x);    // f'(x)
    double g(double x);            // tarnsfromm for fixd pnt

public:
    void bisection(double a, double b, double tol);                
    void newtonRaphson(double x0, double tol, int maxIter);       
    void fixedPointIteration(double x0, double tol, int maxIter);  
};


