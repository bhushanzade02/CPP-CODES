#include <iostream>
#include"hello.hpp"
using namespace std;
double A::table(double x)
{

    for (int i = 0; i < 10; i++)
    {
        cout << x << "X" << i << "=" << x * i << endl;
    }
}