#include<iostream>
using namespace std;

int gcd(int a ,int b)
{
    if((a%b)==0)
    {
        return b;
    }
    return gcd(b,a%b);


};
int main()
{
    double n = 12.7;

    int intgerPart = (int)n; 
    double rem = n - intgerPart;
    cout<<rem;
 
    cout << "Fractional Part: " << rem << endl;


    int denominator = 10; // Assuming 3 decimal places
    int numerator = rem * denominator;

   
    int commonDivisor = gcd(numerator, denominator);

  
    numerator /= commonDivisor;
    denominator /= commonDivisor;

    cout << "Fraction: " << numerator << "/" << denominator << endl;

}
