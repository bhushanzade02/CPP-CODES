#include "taylor.hpp"
#include <iostream>
#include <cmath>
using namespace std;

double A::find_e_x(double x)
{
    double ex = 1;
    double x_by_n = 1.0;
    int n = 1;

    while (abs(x_by_n) > 1e-8)

    {
        x_by_n *= x / n;
        ex += x_by_n;
        n++;
    }
   
    return ex;
}
