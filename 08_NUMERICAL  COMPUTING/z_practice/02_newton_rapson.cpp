#include <iostream>
#include <cmath>
using namespace std;

class RootFinding
{

public:
    double function(double x)
    {

        return x * x - 5 * x + 3;
    }

    double derivative(double x)
    {
        return 2 * x - 5;
    }

    void newtonr(double a, int maxitr)
    {
        double x = a;
        double tol = 0.0001;
        int itr = 0;
        while (itr < maxitr)
        {
            double fx = function(x);
            double dfx = derivative(x);

            if (dfx == 0)
            {
                cout << "newton rapson not execute because because derivatove is zero" << endl;
                return;
            }
            double x_next = x - fx / dfx;
            cout << "iterations:  " << itr << " x " << x << " F(X) " << fx << endl;

            if (fabs(x_next - x) < tol)
            {
                cout << "roots are Found " << x_next << endl;
            }
            x = x_next;
            itr++;
        }

        cout << "Approximate roots are " << x << endl;
    }
};

int main()
{
    RootFinding rf;
    rf.newtonr(0.5, 100);
    return 0;
}