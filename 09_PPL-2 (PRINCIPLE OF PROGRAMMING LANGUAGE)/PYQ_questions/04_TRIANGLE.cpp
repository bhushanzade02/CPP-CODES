#include <iostream>
#include <cmath>   // for cos, sin, acos, asin
#include <iomanip> // for setprecision
using namespace std;

#define PI 3.141592653589793

bool isValidTriangle(double a, double b, double c)
{
    return (a + b > c && a + c > b && b + c > a);
}

double radiansToDegrees(double radians)
{
    return radians * (180.0 / M_PI);
}

int main()
{
    double a, b, c;
    cout << "Enter three sides of triangle: ";
    cin >> a >> b >> c;

    if (!isValidTriangle(a, b, c))
    {
        cout << "Error: Triangle cannot be formed with given side lengths." << endl;
        return 1;
    }

    // Law of Cosines for angle C
    double cosC = (a * a + b * b - c * c) / (2 * a * b);
    double angleC = radiansToDegrees(acos(cosC));

    // Law of Cosines for angle B
    double cosB = (a * a + c * c - b * b) / (2 * a * c);
    double angleB = radiansToDegrees(acos(cosB));

    // Angle A from total 180°
    double angleA = 180.0 - angleB - angleC;

    cout << fixed << setprecision(2);
    cout << angleA<<" ";
    cout << angleB<<" ";
    cout << angleC<<" " ;

    return 0; 
}
