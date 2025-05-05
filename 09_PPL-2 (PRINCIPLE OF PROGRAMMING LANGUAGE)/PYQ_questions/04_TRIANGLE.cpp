#include <iostream>
#include <cmath>
using namespace std;

/*TRIANGLE iNEQUALITY tHEOREM
a + b > c
a + c > b
b + c > a*/

bool inequality(int a, int b, int c)
{
    if (a + b > c && a + c > b && b + c > a)
    {
        cout << "Valid angle " << endl;
        return true;
    }
    else
    {
        cout << "Invalid angle" << endl;
        return false;
    }
};

void computeangles(int a, int b, int c)
{
    // law Of Cosine for finding angle c
    double angle_C_rad = acos((a * a + b * b - c * c) / (2 * a * b));
    double angle_C_deg = angle_C_rad * 180 / M_PI;

    // law of sine for finding angle a and b
    double sin_A = a * sin(angle_C_rad) / c;
    double angle_A_rad = asin(sin_A);
    double angle_A_deg = angle_A_rad * 180 / M_PI;

    double angle_b_deg = 180 - angle_A_deg - angle_C_deg;

    cout << "Angle A :" << angle_A_deg;
    cout << "Angle B :" << angle_b_deg;
    cout << "Angle C :" << angle_C_deg;
}

int main()
{
    int a, b, c;
    cout << "Enter the values of   a,b,and c" << endl;
    cin >> a >> b >> c;

    bool check = inequality(a, b, c);
    if (check == true)
    {
        computeangles(a, b, c);
    }
    else
    {
        cout << "Triangle Inequality Not satisfied" << endl;
    }
    return 0;
}