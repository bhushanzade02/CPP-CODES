#include "disc.hpp"
#include <iostream>
using namespace std;

int Equation::del(int a, int b, int c, int h, int g, int f)
{
    return a * (b * c - f * f) - h * (h * c - g * f) + g * (h * f - b * g);
}

void Equation::classify(int a, int b, int c, int h, int g, int f)
{

    int delta = del(a, b, c, h, g, f);
    int line = (a * b - h * h);

    if (delta != 0)
    {
        if (line > 0)
        {
            cout << "Ellipse" << endl;
        }
        else if (line == 0)
        {
            cout << "Parabola" << endl;
        }
        else
        {
            cout << "Hyperbola" << endl;
        }
    }
    else
    {
        if (line > 0)
        {
            cout << "Two Real Imaginary lines" << endl;
        }
        else if (line == 0)
        {
            cout << "Two Real Parallel Lines" << endl;
        }
        else
        {
            cout << "Two Real Intersecting Lines" << endl;
        }
    }
}