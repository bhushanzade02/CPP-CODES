#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ifstream infile("input.txt"); // Make sure this file exists in the working directory

    if (!infile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int n;
    infile >> n;

    if (n <= 0 || n > 1000) {
        cerr << "Invalid matrix size. Ensure 1 <= n <= 1000.\n";
        return 1;
    }

    vector<vector<double>> Aug(n, vector<double>(n + 1));
    vector<double> X(n);

    // Input coefficients (matrix A and vector B)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= n; ++j)
            infile >> Aug[i][j];

    infile.close();

    // Display Augmented Matrix
    cout << "\nAugmented Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j)
            cout << setw(10) << Aug[i][j] << " ";
        cout << endl;
    }

    // Forward Elimination
    for (int k = 0; k < n - 1; ++k) {
        if (fabs(Aug[k][k]) < 1e-12) {
            cerr << "Zero pivot encountered. Cannot solve using simple Gaussian Elimination.\n";
            return 1;
        }

        for (int i = k + 1; i < n; ++i) {
            double factor = Aug[i][k] / Aug[k][k];
            for (int j = k; j <= n; ++j)
                Aug[i][j] -= factor * Aug[k][j];
        }
    }

    // Display Upper Triangular Matrix
    cout << "\nAfter Forward Elimination:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j)
            cout << setw(10) << Aug[i][j] << " ";
        cout << endl;
    }

    // Back Substitution
    for (int i = n - 1; i >= 0; --i) {
        double sum = Aug[i][n];
        for (int j = i + 1; j < n; ++j)
            sum -= Aug[i][j] * X[j];
        X[i] = sum / Aug[i][i];
    }

    // Output solution
    cout << "\nSolution:\n";
    for (int i = 0; i < n; ++i)
        cout << "X[" << i << "] = " << fixed << setprecision(4) << X[i] << endl;

    return 0;
}
