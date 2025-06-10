#include "lse.hpp"
#include <iostream>
#include <cmath>
using namespace std;

int LeastSquareMethod::line(int n)
{

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


//update sjdsjd

int LeastSquareMethod::parabola(int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i];

        sumx += x[i];
        sumx2 += x[i] * x[i];
        sumx3 += x[i] * x[i] * x[i];
        sumx4 += x[i] * x[i] * x[i] * x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumyx2 += y[i] * x[i] * x[i];
    }

    double d = n * (sumx2 * sumx4 - sumx3 * sumx3) - sumx * (sumx * sumx4 - sumx2 * sumx3) + sumx2 * (sumx * sumx3 - sumx2 * sumx2);

    double Da = sumy * (sumx2 * sumx4 - sumx3 * sumx3) - sumx * (sumxy * sumx4 - sumx3 * sumyx2) + sumx2 * (sumxy * sumx3 - sumx2 * sumyx2);

    double Db = n * (sumxy * sumx4 - sumx3 * sumyx2) - sumy * (sumx * sumx4 - sumx2 * sumx3) + sumx2 * (sumx * sumyx2 - sumxy * sumx2);

    double Dc = n * (sumx2 * sumyx2 - sumxy * sumx3) - sumx * (sumx * sumyx2 - sumxy * sumx2) + sumy * (sumx * sumx3 - sumx2 * sumx2);

    /// by cramers rule
    double a = Da / d;
    double b = Db / d;
    double c = Dc / d;

    cout << "Equation fit parabola is:";
    cout << "y = " << a << "x^2 + " << b << "x + " << c << endl;

    cout << "Predicted values";
    double sumError = 0.0;
    for (int i = 0; i < n; i++)
    {
        double y_pred = a * x[i] * x[i] + b * x[i] + c;
        double error = (y[i] - y_pred) * (y[i] - y_pred);
        sumError += error;
        cout << "x = " << x[i] << "  Actual y = " << y[i] << "  Predicted y = " << y_pred << "  Error^2 = " << error << endl;
    }

    double rmse = sqrt(sumError / n);
    cout << "Total Sum of Squared Errors = " << sumError << endl;
    cout << " (RMSE) = " << rmse << endl;

    return 0;
}

int LeastSquareMethod::exponential(int n)
{
    // double sumx = 0, sumx2 = 0, sumy = 0, sumxy = 0;

    for (int i = 0; i < n; i++)
    {
        if (y[i] <= 0)
        {
            cout << "enter y as positive";
            return -1;
        }
        double Y = log(y[i]);
        sumx += x[i];
        sumx2 += x[i] * x[i];
        sumy += Y;
        sumxy += x[i] * Y;
    }

    double den = n * sumx2 - sumx * sumx;
    double b = (n * sumxy - sumx * sumy) / den;
    double A = (sumy * sumx2 - sumx * sumxy) / den;
    double a = exp(A);

    cout << "y = " << a << " * e^(" << b << "x)\n";
    return 0;
}

int LeastSquareMethod::powerfit(int n)
{
    double sumx = 0, sumx2 = 0, sumy = 0, sumxy = 0;

    for (int i = 0; i < n; i++)
    {

        double X = log(x[i]);
        double Y = log(y[i]);
        sumx += X;
        sumx2 += X * X;
        sumy += Y;
        sumxy += X * Y;
    }

    double den = n * sumx2 - sumx * sumx;
    double b = (n * sumxy - sumx * sumy) / den;
    double A = (sumy * sumx2 - sumx * sumxy) / den;
    double a = exp(A);

    cout << "y = " << a << " * x^" << b;
    return 0;
}

double LeastSquareMethod::Tchebyshev(int k, double x)
{
    if (k == 0)
    {
        return 1;
    }
    if (k == 1)
    {
        return x;
    }
    return 2 * x * Tchebyshev(k - 1, x) - Tchebyshev(k - 2, x);
}