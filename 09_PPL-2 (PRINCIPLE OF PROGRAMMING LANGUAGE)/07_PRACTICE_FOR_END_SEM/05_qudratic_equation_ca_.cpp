#include <iostream>
#include <cmath>
using namespace std;

class Quadratic
{
private:
    int a, b, c;

public:
    Quadratic(double a_, double b_, double c_)
    {
        a = a_;
        b = b_;
        c = c_;
    }

    void factorize()
    {
        int disc = b * b - 4 * a * c;

        if (disc > 0)
        {
            double root1 = -b + sqrt(disc) / (2 * a);
            double root2 = -b - sqrt(disc) / (2 * a);
            cout << "Root 1 " << root1 << " Root 2  " << root2 << endl;
            cout << "Fcatorizes form ofroots are " << a << "(X- " << root1 << ")  (X-" << root2 << ")" << endl;
        }
        else if (disc == 0)
        {

            double root = -b / (2 * a);
            cout << "Z1 = Z2= " << root << endl;
            cout << "Fcatorized form " << a << "(X- " << root << " )^2" << endl;
        }
        else if (disc < 0)
        {

            double realpart = -b / 2 * a;
            double imgpart = sqrt(-disc) / (2 * a);
            cout << "Factorized form " << a << "(X -(" << realpart << " + " << imgpart << " i))(X- (" << realpart << " - " << imgpart << " i)" << endl;
        }
    }
};

int main()
{

    int a, b, c;
    cout << "Enter the cpefficients a ,b ,c";
    cin >> a >> b >> c;

    Quadratic q(a, b, c);
    q.factorize();
    return 0;
}