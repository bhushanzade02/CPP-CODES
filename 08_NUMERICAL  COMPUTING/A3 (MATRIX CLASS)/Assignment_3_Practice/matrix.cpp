#include "Matrix.hpp"
#include <iostream>
#include <fstream>
using namespace std;

Matrix::Matrix()
{
    rows = 3;
    cols = 3;

    // initialize all rows to zero
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            data[i][j] = 0;
        }
    }
}

// funstion to read the matrix form file
void Matrix::inputMatrix(const string &filename)
{
    ifstream inputFile(filename);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j, cols; j++)
        {
            inputFile >> data[i][j];
        }
    }
    inputFile.close();
}

// function to display the matrix

void Matrix::display() const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

// function to add the matrix
Matrix Matrix::add(const Matrix &other) const
{
    Matrix result;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}


Matrix Matrix::sub(const Matrix &other)const {
    Matrix result ;
    for(int i=0;i< rows ;i++){
        for(int j=0 ; j<cols;j++)
        {
            result.data[i][j]=data[i][j]-other.data[i][j];
        }
    }
    return result ;
}