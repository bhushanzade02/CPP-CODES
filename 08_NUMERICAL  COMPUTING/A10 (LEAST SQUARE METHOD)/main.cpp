#include "lse.hpp"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double n;
    cout << "Enter number of data points: ";
    cin >> n;

    int num;
    cout << "ENTRE 1 FOR LINE AND 2 FOR PARABOL" << endl;
    cin >> num;

    if (num == 1)
    {
        LeastSquareMethod obj;
        double result = obj.line(n);
        cout << result << endl;
        return 0;
    }
    else
    {
        LeastSquareMethod obj;
        double result = obj.parabola(n);
        cout << result << endl;
    }
}