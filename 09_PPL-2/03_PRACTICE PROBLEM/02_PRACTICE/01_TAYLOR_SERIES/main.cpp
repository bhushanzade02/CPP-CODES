#include "tay.hpp"
#include <iostream>

using namespace std;
int main()
{
    double x;
    cout << "ENter the value e^x" << endl;
    cin >> x;

    Tay obj;
    double result = obj.e(x);
    cout <<result;
}