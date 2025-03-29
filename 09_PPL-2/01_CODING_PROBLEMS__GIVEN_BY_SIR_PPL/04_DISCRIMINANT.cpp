#include <iostream>
using namespace std;

int Det(int a, int b, int c, int h, int g, int f)
{
    return a * (b * c - f * f) - h * (h * c - f * g) + g * (h * f - (b * g));
};

void classify(int a, int b, int c, int h, int g, int f)
{
    int delta = Det(a, b, c, h, g, f);
    int line = a * b - h * h;

    if (delta != 0)
    {
        if (line > 0)
        {
            cout << "ELLIPSE";
        }
        else if (line == 0)
        {
            cout << "PARABOLA";
        }
        else

        {
            cout << "Hyperbola";
        }
    }
    else
    {
        if (line > 0)
        {
            cout << "TWO iMAGINARY LINES";
        }
        else if (line == 0)
        {
            cout << "Two parallel Lines";
        }
        else
        {
            cout << "Intersecting lines";
        }
    }
};

int main()
{
    int a, b, c, h, g, f;
    cout << "enter values of a,b,c,h,g,f" << endl;
    cin >> a >> b >> c >> h >> g >> f;
    classify(a, b, c, h, g, f);
}