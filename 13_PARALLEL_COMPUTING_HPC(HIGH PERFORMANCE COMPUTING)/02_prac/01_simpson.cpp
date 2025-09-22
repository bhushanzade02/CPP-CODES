#include <iostream>
#include <iomanip> 
#include <cmath>   

using namespace std;

// Function to integrate
double y(double x)
{
    return 1.0 / (1.0 + x * x); // Use 1.0 to ensure floating-point division
}

int main()
{
    // Use double for floating-point calculations
    double x0, xn, h;
    int n;

    cout << "Enter the values of x0, xn, and n (n must be a multiple of 3): " << endl;
    cin >> x0 >> xn >> n;

    // Check if n is a multiple of 3 for Simpson's 3/8 rule
    if (n % 3 != 0)
    {
        cout << "Error: The number of subintervals (n) must be a multiple of 3." << endl;
        return 1;
    }

    // Calculate step size using floating-point arithmetic
    h = (xn - x0) / n;

    // Initialize sum with endpoints
    double sum = y(x0) + y(xn);

    // Loop through intermediate points
    for (int i = 1; i < n; i++)
    {
        double xi = x0 + i * h;
        if (i % 3 == 0)
        {
            sum += 2 * y(xi); 
        }
        else
        {
            sum += 3 * y(xi); 
        }
    }

    // Apply the full Simpson's 3/8 rule formula
    double integralValue = (3.0 * h / 8.0) * sum;

    // Print the result with a set precision for accuracy
    cout << "The approximate value of the integral is: " << setprecision(10) << integralValue << endl;

    return 0;
}