#include "GaussianElimination.hpp"

using namespace std;

int main()
{
    int n;

    cout << "Enter  matrix size: ";
    cin >> n;

    vector<vector<double>> mat(n, vector<double>(n + 1));

    cout << "Enter the matrix ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cin >> mat[i][j];
        }
    }

    GaussianElimination solver(mat);

    cout << " Augmented Matrix:";
    solver.display();

    // solver.eliminate();

    solver.eliminate({{0, 0}, {1, 1}});

    solver.display();

    solver.backSubstitution();

    solver.displaySolution();

    return 0;
}
