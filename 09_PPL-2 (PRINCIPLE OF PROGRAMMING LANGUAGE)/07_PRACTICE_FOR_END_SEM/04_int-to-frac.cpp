#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

void frac_to_ratio(double n)
{
    int I = int(n);
    double F = n - I;
    int num = 1;
    int den = 1;

    while (F - int(F) > 0)
    {
        F *= 10;
        den *= 10;
    }

    num = int(F);
    int factor = gcd(num, den);
    num /= factor;
    den /= factor;
    cout << I << "+" << num << "/" << den;
}

int main()
{
    double num;
    cout << "Enter the The value you wan to enter " << endl;
    cin >> num;

     frac_to_ratio(num);
 

    return 0;
}