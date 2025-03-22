#include <iostream>
using namespace std;


int main()

{
    int n;
    cout << "Enter No of data points" << endl;
    cin >> n;
    double x[100], y[100];
    cout << "Enter x and y values" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "]";
        cin >> x[i];
        cout << "y[" << i <<; "]";
        cin >> y[i];
    }

    double xp;
    cout << "Enter a target value (xp) for interpolation" << endl;
    cin >> xp;
    double yp = 0.0;

    for (int i = 0; i < n; i++)
    {
        double p = 1.0;

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                p *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp += p * y[i];
    }

    cout << "Interpolated value at X=" << xp << " is " << yp << endl;
    return 0;
}