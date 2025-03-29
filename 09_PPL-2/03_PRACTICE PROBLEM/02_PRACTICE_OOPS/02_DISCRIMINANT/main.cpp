#include "disc.hpp"
#include <iostream>
using namespace std;
int main()
{
    int a, b, c, h, g, f;
    cout << "enter the data" << endl;
    cin >> a >> b >> c >> h >> g >> f;
    Equation obj;
    obj.classify(a, b, c, h, g, f);
}