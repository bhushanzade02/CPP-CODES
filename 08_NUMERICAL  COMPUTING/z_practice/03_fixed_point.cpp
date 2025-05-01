#include <iostream>
#include <cmath>
using namespace std;

class RootFinding
{
public:
    double g(double x)
    {
        return x * x - 5 * x + 3;
    }

    void fixedpointiteration(double x0, int maxitr)
    {

        double x = x0;
        int itr = 0;
        double tol = 0.001;

        while (itr < maxitr)
        {
            double x_next = g(x);
            cout << "Iteration : " << itr << " X :" << x << endl;

            if (fabs(x_next - x) < tol)
            {
                cout << "Roots are found " << x_next << endl;
                return;
            }
            x = x_next;
            itr++;
        }
    }
};

int main()
{
    RootFinding rf;
    cout << "Fiexd Point Iteration " << endl;
    rf.fixedpointiteration(1, 12);
}