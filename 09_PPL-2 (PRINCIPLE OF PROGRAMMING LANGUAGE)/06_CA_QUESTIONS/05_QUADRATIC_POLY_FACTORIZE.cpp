#include <iostream>
#include <cmath>
#include<fstream>
using namespace std;

//Quadratic polynomial equation 
class Quadratic
{

private:
    double a, b, c;

public:
    Quadratic(double a_, double b_, double c_)
    {
        a = a_;
        b = b_;
        c = c_;
    }

    void factorize()
    {

        double disc = b * b - 4 * a * c;

        if (disc > 0)
        {
            double root1 = (-b + sqrt(disc)) / (2 * a);
            double root2 = (-b - sqrt(disc)) / (2 * a);
            cout << "Real and Distint Roots are" << endl;
            cout << "z1 =" << root1 << ",z2=" << root2 << endl;
            cout << "Factoial Form: a(x-" << root1 << ")(x- " << root2 << ")" << endl;
        }
        else if (disc == 0)
        {
            double root = -b / (2 * a);
            cout << "Real and distict Roots are" << endl;
            cout << "z1 = z2= " << root << endl;
            cout << "Factorized Form : a(x" << root << ")^2" << endl;
        }
        else if (disc < 0)
        {

            double realpart = -b / (2 * a);
            double imgpart = sqrt(-(disc)) / (2 * a);

            cout << "complex Roots :" << endl;
            cout << "z1 = " << realpart << "+" << imgpart << "i" << endl;
            cout << "z1 = " << realpart << "-" << imgpart << "i" << endl;
            cout << "FActorized Form:a(x- (" << realpart << "+" << imgpart << "i))(x-(" << realpart << "-" << imgpart << "i))" << endl;
            ;
        }
    }
};

int main()
{

    int a, b, c;
    cout << "Enter a Coefficinet" << endl;
    cin >> a >> b >> c;

    Quadratic q(a, b, c);
    q.factorize();
    return 0;
}