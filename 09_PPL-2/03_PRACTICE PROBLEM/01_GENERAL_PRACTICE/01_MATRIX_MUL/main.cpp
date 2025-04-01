#include "matrix.hpp"
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter matrix size" << endl;
    cin >> n;
    Matrix obj;
    obj.Matmul(n);
}
