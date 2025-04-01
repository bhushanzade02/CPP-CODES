#include "matrix.hpp"
#include <iostream>
using namespace std;

int Matrix::Matmul(int n)
{

    int mat1[n][n];
    int mat2[n][n];
    int c[n][n] = {0};
    cout << "\nEnter 1st Matrix elements\n"
         << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat1[i][j];
        }
    }

    cout << "\nEnter 2nd Matrix elements\n"
         << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat2[i][j];
        }
    }

    cout << "1st Matrix elements are" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat1[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "2nd Matrix Elements are" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat2[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Matrix MUltipliacation" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {

                c[i][j] += mat1[i][j] * mat2[i][j];
            }
        }
    }

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
