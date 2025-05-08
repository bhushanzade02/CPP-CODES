#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

bool isvalidtriangle(double a, double b, double c)
{
    return (a + b > c && a + c > b && b + c > a);
};

double radiantodegree(double radian)
{
    return radian * (180 / M_PI);
}

int main()
{
    double a, b, c;
    cout << "Enter the Values a , b , c";
    cin >> a >> b >> c;

    double cosc = (a * a + b * b - c * c) / (2 * a * b);
    double anglec = radiantodegree(acos(cosc));

    double cosb = (a * a + c * c - b * b) / (2 * a * c);
    double angleb = radiantodegree(acos(cosb));

    double angleA = 180 - anglec - angleb;

    cout << fixed << setprecision(2);
    cout << angleA << " " << endl;
    cout << angleb << " " << endl;
    cout << anglec << " " << endl;
    return 0;
}
