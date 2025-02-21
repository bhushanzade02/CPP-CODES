#include "Matrix.hpp"
#include <iostream>
#include <fstream>
using namespace std;

Matrix::Matrix()
{
    rows = 3;
    cols = 3;

    // Initialize all values to zero
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            map[i][j] = 0;
        }
    }
}

// Funcn read the matrix from a file
void Matrix::inputMatrix(const string &filename)
{
    ifstream inputFile(filename);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            inputFile >> map[i][j];
        }
    }

    inputFile.close();
}

// Funct to display the matrix
void Matrix::display() const
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

// Function For Addition
Matrix Matrix::add(const Matrix &nextM) const
{
    Matrix result;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result.map[i][j] = map[i][j] + nextM.map[i][j];
        }
    }
    return result;
}

//  For Subtraction
Matrix Matrix::sub(const Matrix &nextM) const
{
    Matrix result;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result.map[i][j] = map[i][j] - nextM.map[i][j];
        }
    }
    return result;
}

bool Matrix::isidentity() const
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j && map[i][j] != 1) // Check diagonal elements
                return false;
            if (i != j && map[i][j] != 0)
                return false;
        }
    }
    return true;
}
