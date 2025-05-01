

#include <iostream>
#include <cmath>

class RootFinding {
private:
    double function(double x);      // f(x)
    double derivative(double x);    // f'(x)
    double g(double x);            // tarnsfromm for fixd points

public:
    void bisection(double a, double b); 
    void newtonRaphson(double x0, int maxIter); 
    void fixedPointIteration(double x0, int maxIter);  
};


