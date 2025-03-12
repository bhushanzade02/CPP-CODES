#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void gaussSeidel(vector<vector<double>> &A, vector<double> &b, vector<double> &x, int maxIterations, double tol)
{
    int n = A.size();
    
    for (int iter = 0; iter < maxIterations; iter++)
    {
        vector<double> x_old = x;

        for (int i = 0; i < n; i++)
        {
            double sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    sum += A[i][j] * x[j];
                    cout<<sum<<endl;
                }
            }
            x[i] = (b[i] - sum) / A[i][i];  // Gauss-Seidel formula
        }

        // Convergence check
        double error = 0;
        for (int i = 0; i < n; i++)
        {
            error += abs(x[i] - x_old[i]);
        }
        if (error < tol)
        {
            cout << "Converged in " << iter + 1 << " iterations.\n";
            break;
        }
    }

    // Print final solution
    cout << "Solution:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

int main()
{
    vector<vector<double>> A = {
        {4, 1, -1},
        {1, -5, 2},
        {2, -2, -7}};

    vector<double> b = {13, -8, -2};
    vector<double> x = {0, 0, 0}; // Initial guesses

    int maxIterations = 100;
    double tolerance = 1e-6;

    gaussSeidel(A, b, x, maxIterations, tolerance);

    return 0;
}
