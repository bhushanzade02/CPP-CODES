#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    double x[100], y[100];
    double sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0;

    cout << "Enter number of data points: ";
    cin >> n;

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

    cout << "\nSummations:\n";
    cout << "Sum of x = " << sumx << endl;
    cout << "Sum of y = " << sumy << endl;
    cout << "Sum of xy = " << sumxy << endl;
    cout << "Sum of x^2 = " << sumx2 << endl;

    double a = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    double b = (sumy - a * sumx) / n;

    cout << "\nEquation of best fit: y = " << a << "x + " << b << endl;

    double sumError = 0.0;
    cout << "\nPredicted values and errors:\n";
    for (int i = 0; i < n; i++)
    {
        double y_pred = a * x[i] + b;
        double error = (y[i] - y_pred) * (y[i] - y_pred);
        sumError += error;
        cout << "x = " << x[i] << "  Actual y = " << y[i] << " Predicted y = " << y_pred
             << "  Error (y - y_pred) = " << error << endl;
    }

    cout << "\nTotal Sum of Errors = " << sumError << endl;

    double rmse = sqrt(sumError / n);
    cout << "RMSE : " << rmse;

    return 0;
}
