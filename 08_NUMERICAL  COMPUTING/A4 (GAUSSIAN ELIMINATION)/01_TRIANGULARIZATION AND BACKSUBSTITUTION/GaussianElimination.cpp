#include "GaussianElimination.hpp"

using namespace std;

GaussianElimination::GaussianElimination(vector<vector<double>> mat)
{
    matrix = mat;
    n = matrix.size();
    solution.resize(n);
}

// void GaussianElimination::eliminate() {
//     for (int k = 0; k < n; k++) {

//         double pivot = matrix[k][k];
//         for (int j = k; j < n + 1; j++) {
//             matrix[k][j] /= pivot;
//         }

//         for (int i = k + 1; i < n; i++) {
//             double factor = matrix[i][k];
//             for (int j = k; j < n + 1; j++) {
//                 matrix[i][j] -= factor * matrix[k][j];
//             }
//         }
//     }
// }

void GaussianElimination::backSubstitution()
{
    for (int i = n - 1; i >= 0; i--)
    {
        solution[i] = matrix[i][n];

        for (int j = i + 1; j < n; j++)
        {
            solution[i] -= matrix[i][j] * solution[j];
        }
    }
}

void GaussianElimination::display()
{
    for (const auto &row : matrix)
    {
        for (double val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

void GaussianElimination::displaySolution()
{
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
}

void GaussianElimination::eliminate(const vector<pair<int, int>> &pivots)
{
    for (const auto &ppos : pivots)
    {
        int row = ppos.first;
        int pcol = ppos.second;

        double pivot = matrix[row][pcol];
        if (pivot == 0)
        {
            cout << "Zero pivot" ;
            continue;
        }

        for (int j = pcol; j < n + 1; ++j)
        {
            matrix[row][j] /= pivot;
        }

        for (int i = 0; i < n; ++i)
        {
            if (i == row)
                continue;
            double factor = matrix[i][pcol];
            for (int j = pcol; j < n + 1; ++j)
            {
                matrix[i][j] -= factor * matrix[row][j];
            }
        }
    }
}

// eliminate({{0,0}, {1,1}, {2,2}});



