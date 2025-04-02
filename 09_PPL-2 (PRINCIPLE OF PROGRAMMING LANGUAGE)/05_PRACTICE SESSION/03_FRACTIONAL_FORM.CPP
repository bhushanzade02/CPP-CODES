#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)

        return a;

    return gcd(b, a % b);
}
int main()
{
    double n = 9.25;

    int I = int(n);

    double f = n - I;
    int num, den = 1;
    while (f - (int)f > 1e-8)
    {
        f *= 10;
        den *= 10;
    }
    num = int(f);
    int factor = gcd(num, den);
    num /= factor;
    den /= factor;
    cout << I << "+" << num << "/" << den;
}