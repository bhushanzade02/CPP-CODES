#include "fract.hpp"
#include <iostream>
#include<fstream>
using namespace std;
int Form::gcd(int a, int b)
{

    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}
int Form::fract(double n)
{
    int I = (int)n;
    double F = n - I;
    int num, den = 1;

    while (F - (int)F > 0)
    {
        F *= 10;
        den *= 10;
    }
    num = (int)F;

    int factor = gcd(num, den);
    num /= factor;
    den /= factor;
    cout << I << "+" << num << "/" << den << endl;
}
