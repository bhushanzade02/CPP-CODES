#include "tay.hpp"
#include<cmath>
double Tay::e(double x)
{

    double ex = 1;
    double xbyn = 1;
    int n = 1;
    while (fabs(xbyn) > 1e-8)
    {
        xbyn *= x / n;
        ex += xbyn;
        n++;
    }
    return ex;
}