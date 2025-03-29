#include "nsystem.hpp"
#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "enter a value" << endl;
    cin >> num;

    Numbersystem obj;
    int result = obj.dectobin(num);
    cout << result<<endl;

    int result2 = obj.dectooctal(num);
    cout << result2 << endl;
}