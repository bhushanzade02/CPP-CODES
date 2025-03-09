#include "Matrix.hpp"

int main()
{
    int r1, c1, r2, c2;
    cout << "Enter rows and cols 1st matrix: ";
    cin >> r1 >> c1;
    Matrix mat1(r1, c1);
    mat1.inputMatrix();

    cout << "Enter rows and cols 2nd matrix: ";
    cin >> r2 >> c2;
    Matrix mat2(r2, c2);
    mat2.inputMatrix();

    if (r1 == r2 && c1 == c2)
    {
        Matrix sum = mat1.add(mat2);
        Matrix diff = mat1.sub(mat2);

        cout << "Addition ";
        sum.display();

        cout << "Subtraction ";
        diff.display();
    }
    else
    {
        cout << "matrics size is not same\n\n";
    }

    if (r1 == c1)
    {
        cout << "Determinant of 1st : " << mat1.determinant() << endl;
        if (mat1.isIdentity())
        {
            cout << " it is Identity matrix\n";
        }
        else
        {
            cout << "It is NOT identity ";
        }
    }

    int n, m;
    cout << "Enter no. of rows cols for augmented matrix: ";
    cin >> n >> m;

    Matrix augmentedMatrix(n, m);
    augmentedMatrix.inputMatrix();
    augmentedMatrix.gaussianElimination();

    return 0;
}
