#include"matrix.hpp"
#include<iostream>
using namespace std ;

int main()
{
    Matrix mat1 , mat2, sum , subt ;
    string filename1 ,filename2;

    cin>>filename1;
    mat1.inputMatrix(filename1);

    cin>>filename2;
    mat2.inputMatrix(filename2);

    sum=mat1.add(mat2);
    subt=mat1.sub(mat2);

    cout<<"sum of matrices "<<endl;
    sum.display();

    cout<<"subtraction of metrices "<<endl;
    subt.display();
    return 0;


}