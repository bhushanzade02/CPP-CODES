#include "taylor.hpp"
#include <iostream>
using namespace std;
int main()
{
    double x;
    cout << "ENter value of X" << endl;
    cin >> x;

    A obj;
    double result = obj.find_e_x(x);
    cout << "e^" << x << "=" << result << endl;
    return 0;
}