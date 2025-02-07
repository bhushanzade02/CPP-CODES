

#include <iostream>
#include <cmath>

class RootFinding {
private:
    double function(double x);      // Function f(x)
    double derivative(double x);    // Derivative f'(x) for Newton-Raphson
    double g(double x);             // Transformation function for Fixed-Point

public:
    void bisection(double a, double b, double tol);                
    void newtonRaphson(double x0, double tol, int maxIter);       
    void fixedPointIteration(double x0, double tol, int maxIter);  
};


