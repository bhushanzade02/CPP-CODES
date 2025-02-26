#include <vector>
#include <iostream>
using namespace std;


class GaussianElimination {
private:
    vector<vector<double>> matrix;
    int n; // Size of the matrix (assuming square)

public:
    // Constructor
    GaussianElimination(vector<vector<double>> mat);

    // Function to perform Gaussian elimination
    void eliminate();

    // Function to display the matrix
    void display();
};
