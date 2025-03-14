#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

class Matrix
{
private:
    vector<vector<double>> d;
    int r, c;

public:
    Matrix();
    void load(const string &f);
    static void loadB(const string &filename, vector<double> &b);
    void show() const;
    Matrix add(const Matrix &m) const;
    Matrix sub(const Matrix &m) const;
    bool isId() const;
    double det() const;
    void ge(vector<double> &b, vector<double> &x);
    bool isDiagDom() const;
    void gs(vector<double> &b, vector<double> &x, int maxItr, double tol);
};
