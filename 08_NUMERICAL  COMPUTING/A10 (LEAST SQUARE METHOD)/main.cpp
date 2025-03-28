#include "lse.hpp"
#include <iostream>
using namespace std;
int main()
{
    double n;
    cout << "Enter number of data points: ";
    cin >> n;


    A obj;
    double result = obj.lse(n);
    cout <<result << endl;
    return 0;
} 