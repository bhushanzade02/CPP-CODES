
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Matrix
{
private:
    int data[3][3];  // 3x3 matrix
    int rows, cols;

public:
    Matrix();

    // Function to read matrix from a file
    void inputMatrix(const string &filename);

    // Function to display the matrix
    void display() const;

    // Function to add matrices
    Matrix add(const Matrix &other) const;

    // Function to subtract matrices
    Matrix sub(const Matrix &other) const;

    bool isidentity() const;

    
};

