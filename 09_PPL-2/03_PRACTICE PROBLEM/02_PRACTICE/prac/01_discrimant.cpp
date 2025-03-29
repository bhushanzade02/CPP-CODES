#include <iostream>
using namespace std;

int del(int a, int b, int c, int h, int g, int f)
{
    return (a * (b * c - f * f) - h * (h * c - g * f) + g * (h * f - b * g));
};

void classify(int a, int b, int c, int h, int g, int f)
{
    int delta = del(a, b, c, h, g, f);
    int line = (a * b - h * h);

    if (delta != 0)
    {
        if ((a * b - h * h) > 0)
        {
            cout << "ellipse" << endl;
        }
        else if ((a * b - h * h) == 0)
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
        if ((a * b - h * h) > 0)
        {
            cout << "Two real Imaginary Lines" << endl;
        }
        else if ((a * b - h * h) == 0)
        {
            cout << "Two Real Parallel Lines" << endl;
        }
        else
        {
            cout << "Two Intersecting Lines" << endl;
        }
    }
}

int main()
{
    int a, b, c, h, g, f;
    cout << "enter a values" << endl;
    cin >> a >> b >> c >> h >> g >> f;
    classify(a, b, c, h, g, f);
}
