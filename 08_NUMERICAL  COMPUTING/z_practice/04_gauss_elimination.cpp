#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;
int main()
{
    int n;
    cout << "ENter a number of varibels "; // i/p:  2 ----> (2 x 2 matrix)
    cin >> n;

    double A[10][11], B[10], Aug[10][10];

    cout << "Enter the Coefficients of Matrix A (" << n << "X" << n << "):\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter a Variables for Vector B \n"
         << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    // form the augmented Matrix

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Aug[i][j] = A[i][j];
        }
        Aug[i][n] = B[i];
    }

    // Display The Augmented Matrix

    cout << "\n Augmented Matrix : \n"
         << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << Aug[i][j] << " \t";
        }
        cout << endl;
    }

    // forward Elimination (Make an Upper Traingular matrix)

    for (int k = 0; k < n - 1; k++)
    {
        for (int i = k + 1; i < n; i++)
        {
            double factor = Aug[i][k] / Aug[k][k];

            for (int j = k; j <= n; j++)
            {
                Aug[i][j] = Aug[i][j] - factor * Aug[k][j];
            }
        }
    }

    cout << "\n FOrward elimination : \n"
         << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << Aug[i][j] << " \t";
        }
        cout << endl;
    }


    // back Substitution
double X[10];

for (int i = n - 1; i >= 0; i--)
{
    double sum = Aug[i][n];

    for (int j = i + 1; j < n; j++)
    {
        sum -= Aug[i][j] * X[j];
    }

    X[i] = sum / Aug[i][i];
}


    // Display the solution
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "X[" << i << "] = " << fixed << setprecision(4) << X[i] << endl;
    }
}