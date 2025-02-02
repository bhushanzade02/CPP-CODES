#include <cmath>
using namespace std;
double fun(double x)
{

    return pow(x, 3) - 2 * x - 2;
}

int main()
{
    double a, b, c, eps;
    a = 1;
    b = 2;
    eps = 0.001;
    int count = 0;
    while (fabs(b - a) > eps)
    {
        c = (a + b) / 2;
        if (fun(a) * fun(c) < 0)
        {
            b = c;
        }
        else if (fun(c) == 0)
        {
            cout << "root is " << c << endl;
            break;
        }
        else
        {
            a = c;
        }

        cout << "iteration no" << count++ << endl;
        cout << "value of c" << c << endl;
    }
}