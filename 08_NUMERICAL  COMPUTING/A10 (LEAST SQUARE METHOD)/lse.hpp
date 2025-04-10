#include <iostream>
#include <cmath>
#define MAX 100

class LeastSquareMethod
{
public:
    double x[MAX], y[MAX];
    double sumx = 0, sumx2 = 0, sumx3 = 0, sumx4 = 0;
    double sumy = 0, sumxy = 0, sumyx2 = 0;



    int line(int x);
    int parabola(int x);
    
    int exponential(int x);
    int powerfit(int x);
};