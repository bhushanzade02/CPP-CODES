#include <iostream>
#include <vector>
using namespace std;

double langrange(const vector<double> &x, const vector<double> &y, double z)
{
    int n = x.size();
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        double term = y[i];
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                term *= (z - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter number of Data Points " << endl;
    cin >> n;

    vector<double> x(n), y(n);
    cout << "enter the x and f(x) values:\n"
         << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        cin >> y[i];
    }

    double z;
    cout << "Enter the value between 1 and 20 " << endl;
    cin >> z;

    // if (z <= 1 || z >= 20)
    // {
    //     cout << "Error : z must be in 1 and 20" << endl;
    //     return 1;
    // }

    double result = langrange(x, y, z);
    cout << "The Interpolated value at z = " << z << "is f(z)" << result << endl;
    return 0;
}