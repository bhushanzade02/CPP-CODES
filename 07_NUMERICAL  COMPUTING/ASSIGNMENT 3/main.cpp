#include "Matrix.hpp"
#include <iostream>
using namespace std;

int main()
{
    Matrix mat1, mat2, sum, subt;

    // Get matrix filenames from the user
    string filename1, filename2;
    
    cout << "Enter the filename for the first matrix: ";
    cin >> filename1;
    mat1.inputMatrix(filename1);

    cout << "Enter the filename for the second matrix: ";
    cin >> filename2;
    mat2.inputMatrix(filename2);

    // Perform matrix addition and subtraction
    sum = mat1.add(mat2);
    subt = mat1.sub(mat2);

    // Display results
    cout << "Sum of matrices:" << endl;
    sum.display();

    cout << "Subtraction of two matrices:" << endl;
    subt.display();


    
    // Check if the first matrix is an identity matrix
    if (mat2.isidentity())
        cout << "matrix is an identity matrix!" << endl;
    else
        cout << "matrix is NOT an identity matrix!" << endl;


    return 0;
}
