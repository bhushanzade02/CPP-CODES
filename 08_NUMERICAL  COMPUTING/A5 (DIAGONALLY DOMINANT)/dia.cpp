#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void isDiagonallyDominant(const vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < matrix.size(); j++)
        {
            if (i != j)
            {
                sum += abs(matrix[i][j]);
            }
        }

        if (abs(matrix[i][i]) < sum) 
        {
            cout << "Matrix is NOT diagonally dominant" << endl;
            return;
        }
    }

    cout << "Matrix is diagonally dominant" << endl;
}
