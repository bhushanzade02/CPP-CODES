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
            data[i][j] = 0;
        }
    }
}

// Function to read the matrix from a file
void Matrix::inputMatrix(const string &filename)
{
    ifstream inputFile(filename);  // Open the file

    
    // Read the matrix values from the file
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            inputFile >> data[i][j];  // Read each value
        }
    }

    inputFile.close();  // Close the file
}

// Function to display the matrix
void Matrix::display() const
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to add two matrices
Matrix Matrix::add(const Matrix &other) const
{
    Matrix result;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;  
}

// Function to subtract two matrices
Matrix Matrix::sub(const Matrix &other) const
{
    Matrix result;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;  
}


bool Matrix::isidentity()const
{
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j && data[i][j] != 1) // Check diagonal elements
                return false;
            if (i != j && data[i][j] != 0) // Check off-diagonal elements
                return false;
        }
    }
    return true; // If all checks pass, it's an identity matrix
}

