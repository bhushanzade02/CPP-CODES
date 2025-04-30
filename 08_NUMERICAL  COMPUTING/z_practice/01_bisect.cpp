#include <iostream>
using namespace std;

class RootFinding
{

public:
    double function(double x)
    {
        return (4 * x * x * x) - (3 * x);
    }

    void BisectionMethod(double a, double b)
    {

        double tol = 0.01;

        if (function(a) * function(b) >= 0)
        {
            cout << "f(a) and f(b)  must have opposite signs it is not coorect" << endl;
            return;
        }

        double mid;
        int itr = 0;

        while ((b - a) >= tol)
        {
            mid = (a + b) / 2.0;
            cout << "Iteration: " << itr++ << " mid: " << mid << " f(mid): " << function(mid) << endl;

            if (function(mid) == 0)
                break;
            else if (function(mid) * function(a) < 0)
            {
                b = mid;
            }
            else
            {
                a = mid;
            }
        }
        cout << "Approximte roots are :  " << mid << endl;
    }
};

int main()
{

    RootFinding rf;
    double a = 0.5, b = 1.0;
    rf.BisectionMethod(a, b); // Run Bisection Method
    return 0;
}