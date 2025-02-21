#include "Matrix.hpp"
#include <iostream>
using namespace std;

int main()
{
    Matrix mat1, mat2, sum, subt, mat3;
    string filename1, filename2, filename3;

    cout << "Enter filename of 1st  matrix: ";
    cin >> filename1;
    mat1.inputMatrix(filename1);

    cout << "Enter filename of 2nd matrix: ";
    cin >> filename2;
    mat2.inputMatrix(filename2);

    sum = mat1.add(mat2);
    subt = mat1.sub(mat2);

    cout << "ADDITION :" << endl;
    sum.display();

    cout << "SUBTRACTION:" << endl;
    subt.display();

    cout << "Enter filename of Identity matrix: ";
    cin >> filename3;
    mat3.inputMatrix(filename3);

    if (mat3.isidentity())
        cout << "matrix is an identity matrix!" << endl;
    else
        cout << "matrix is NOT an identity matrix!" << endl;

    return 0;
}
