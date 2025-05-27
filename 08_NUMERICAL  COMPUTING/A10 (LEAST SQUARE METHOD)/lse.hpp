#include <iostream>
#include <cmath>
#define MAX 1000

class LeastSquareMethod
{
public:
    double x[MAX], y[MAX];
    int n;
    double sumx = 0, sumx2 = 0, sumx3 = 0, sumx4 = 0;
    double sumy = 0, sumxy = 0, sumyx2 = 0;

    int line(int x);
    int parabola(int x);




 /*  Numerical computing lab assignment for 
     Least square method for line , parabola ,
     exponential , powerfit , Tchebyshev 
 */

    int exponential(int x);
    int powerfit(int x);
    double Tchebyshev(int k, double x);

};