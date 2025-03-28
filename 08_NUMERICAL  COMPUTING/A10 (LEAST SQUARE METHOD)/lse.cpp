#include "lse.hpp"
#include <iostream>
#include <cmath>
using namespace std;

int A::lse(int n)
{
   
    double x[100], y[100];
    double sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i];
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumx2 += x[i] * x[i];
    }

    cout << "Summations:";
    cout << "Sum of x = " << sumx << endl;
    cout << "Sum of y = " << sumy << endl;
    cout << "Sum of xy = " << sumxy << endl;
    cout << "Sum of x^2 = " << sumx2 << endl;

    
    double a = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    double b = (sumy - a * sumx) / n;

    cout << "Equation of best fit: y = " << a << "x + " << b << endl;

    double sumError = 0.0;
    cout << "/nPredicted values and errors:";
    for (int i = 0; i < n; i++)
    {
        double y_pred = a * x[i] + b;
        double error = (y[i] - y_pred) * (y[i] - y_pred);
        sumError += error;
        cout << "x = " << x[i] << "  Actual y = " << y[i] << " Predicted y = " << y_pred
             << "  Error (y - y_pred)^2 = " << error << endl;
    }

    cout << "Total Sum of Errors = " << sumError << endl;

    double rmse = sqrt(sumError / n);
    cout << "RMSE : " << rmse << endl;
}
