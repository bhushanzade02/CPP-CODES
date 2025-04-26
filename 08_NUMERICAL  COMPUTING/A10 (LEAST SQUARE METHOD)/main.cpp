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
    cout << "ENTRE 1 FOR LINE AND 2 FOR PARABOL 3 FOR  EXPONENTIL AND 4 FOR power fit  and 5 for Tchebyshev " << endl;
    cin >> num;

    if (num == 1)
    {
        LeastSquareMethod obj;
        double result = obj.line(n);
        cout << result << endl;
        return 0;
    }
    else if (num == 2)
    {
        LeastSquareMethod obj;
        double result = obj.parabola(n);
        cout << result << endl;
    }
    else if (num == 3)
    {
        LeastSquareMethod obj;
        double result = obj.exponential(n);
        cout << result << endl;
    }
    else if (num == 4)
    {
        LeastSquareMethod obj;
        double result = obj.powerfit(n);
        cout << result << endl;
    }
    else if (num == 5)
    {
        LeastSquareMethod obj;
        int k;
        double x;
        cout << "enter the degree";
        cin >> k;
        cout << "enter the value of x: ";
        cin >> x;
        double result = obj.Tchebyshev(k, x);
        cout << result;
    }
}
