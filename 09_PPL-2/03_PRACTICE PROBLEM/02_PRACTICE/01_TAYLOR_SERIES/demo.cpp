#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int x;
    cout << "enter the number you want to calculate e^x " << endl;
    cin >> x;

    double ex = 1;
    double xbyn = 1.0;
    double n = 1;
    while (abs(xbyn) > 1e-8)
    {
        xbyn *= x / n;
        ex += xbyn;
        n++;
    }
    cout << "e^" << x << " = " << fixed << ex << endl;

}