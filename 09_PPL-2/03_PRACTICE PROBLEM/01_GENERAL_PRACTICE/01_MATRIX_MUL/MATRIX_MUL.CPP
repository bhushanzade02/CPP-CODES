#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n;
    cout << "Enter size of matrix" << endl;
    cin >> n;

    // int mat1[n][n];
    // int mat2[n][n];
    // int c[n][n] = {0};

    vector<vector<int>> mat1(n, vector<int>(n));
    vector<vector<int>> mat2(n, vector<int>(n));
    vector<vector<int>> c(n, vector<int>(n, 0));

    cout << "Enter a Matrix Elements" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter 2nd Matrix elements" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat2[i][j];
        }
    }

    cout << "\n Your entered Matrix is \n"
         << endl;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cout << mat1[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\n You Enterd MAtrix elemnts are \n"
         << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat2[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                c[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    cout << "Multiplication of two Matrices" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << c[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

