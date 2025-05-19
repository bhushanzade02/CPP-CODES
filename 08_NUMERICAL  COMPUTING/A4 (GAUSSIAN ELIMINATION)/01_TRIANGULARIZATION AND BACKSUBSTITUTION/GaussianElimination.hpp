
#include <vector>
#include <iostream>

using namespace std;

class GaussianElimination
{
private:
    vector<vector<double>> matrix;
    vector<double> solution;
    int n;

public:
    GaussianElimination(vector<vector<double>> mat);

    
    // void eliminate();
    void eliminate(const vector<pair<int, int>> &pivots);

    void backSubstitution();

    void display();

    void displaySolution();
};
