#include "nsystem.hpp"
#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "enter a value" << endl;
    cin >> num;

    int base;
    cout << "enter a base value" << endl;
    cin >> base;

    Numbersystem obj;

    if (base == 2)
    {
        cout << obj.dectobin(num) << endl;
    }
    else if (base == 8)
    {
        cout << obj.dectooctal(num) << endl;
    }
    else if (base == 16)
    {
        cout << obj.dectohex(num) << endl;
    }
    else if (base == 10)
    {
        cout << num;
    }
}