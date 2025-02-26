
#include <vector>
#include <iostream>

using namespace std;

class GaussianElimination {
private:
    vector<vector<double>> matrix;
    vector<double> solution;
    int n; // Size of the matrix (assuming square)

public:
    // Constructor
    GaussianElimination(vector<vector<double>> mat);

    // Function to perform Gaussian elimination (Forward elimination)
    void eliminate();

    // Function to perform back-substitution and find the solution
    void backSubstitution();

    // Function to display the matrix
    void display();

    // Function to display the solution vector
    void displaySolution();
};
