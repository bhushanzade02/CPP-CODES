#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<double>> data;
    vector<double> solution;
    int rows, cols;

public:
    Matrix(int r, int c);
    void inputMatrix();
    void display() const;
    Matrix add(const Matrix &other) const;
    Matrix sub(const Matrix &other) const;
    bool isIdentity() const;
    double determinant() const;
    Matrix inverse() const;
    void gaussianElimination();
    void backSubstitution();
    void setValue(int row, int col, double val);
};

#endif // MATRIX_HPP
