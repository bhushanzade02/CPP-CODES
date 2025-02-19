#include<iostream>
#include<fstream>
#include<string>
using namespace std ;

class Matrix {
    private:
    int data[3][3];
    int rows, cols ;
    public :
     Matrix();
    
    void inputMatrix(const string &filename);

    void display() const;

    Matrix add(const Matrix &other ) const;

    Matrix sub(const Matrix &other )const ;



};