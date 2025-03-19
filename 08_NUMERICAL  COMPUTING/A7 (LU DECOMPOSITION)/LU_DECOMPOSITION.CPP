#include <iostream>
using namespace std;

int main()
{
    int A[3][3], L[3][3] = {0}, U[3][3] = {0};

    cout << "Enter element ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> A[i][j];
        }
    }
cout<<"\n";

    cout << "Input Matrix (A):\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

  
    for (int i = 0; i < 3; i++)
    {
        
        for (int j = i; j < 3; j++)
        {
            U[i][j] = A[i][j];
            for (int k = 0; k < i; k++)
            {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }

       
        for (int j = i; j < 3; j++)
        {
            if (i == j)
                L[i][i] = 1; 
            else
            {
                L[j][i] = A[j][i];
                for (int k = 0; k < i; k++)
                {
                    L[j][i] -= L[j][k] * U[k][i];
                }
                L[j][i] /= U[i][i];
            }
        }
    }

   
    cout << "\nUpper Triangular Matrix (U):\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << U[i][j] << " ";
        }
        cout << endl;
    }

    
    cout << "Lower Triangular Matrix (L):\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
