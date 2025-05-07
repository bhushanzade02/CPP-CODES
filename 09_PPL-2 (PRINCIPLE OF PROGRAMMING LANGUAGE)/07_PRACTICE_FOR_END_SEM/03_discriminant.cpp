#include <iostream>
using namespace std;

int det(int a, int b, int c, int h, int g, int f)
{
    return a * (b * c - f * f) - h * (h * c - f * g) + g * (h * f - (g * h));

    // a * (b * c - f * f) - h * (h * c - f * g) + g * (h * f - (b * g));
};

void classify(int a, int b, int c, int h, int g, int f)
{
    int delta = det(a, b, c, h, g, f);

    int line = (a * b) - (h * h);

    if (delta != 0)
    {
        if (line > 0)
        {

            if (a == b && h == 0)
            {
                cout << "Circle ";
            }
            else
            {
                cout << "Ellipse";
            }
        }
        if (line == 0)
        {
            cout << "Parabola";
        }
        if (line < 0)
        {
            cout << "Hyperbola";
        }
    }

    else

    {
        if (line > 0)
        {
            cout << " two imaginianry Line ";
        }
        if (line == 0)
        {
            cout << "two Parallel Lines";
        }

        if (line < 0)
        {
            cout << "Intersecting Lines ";
        }
    }
}

int main()
{

    int a, b, c, h, g, f;
    cout << "Enter the values " << endl;
    cin >> a >> b >> c >> h >> g >> f;

    classify(a, b, c, h, g, f);
}
