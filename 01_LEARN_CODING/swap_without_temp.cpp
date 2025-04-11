#include <iostream>
using namespace std;

int main()
{
    int a = 20;
    int b = 30;
    cout << "Input " << endl;

    cout << "a: " << a << "\n"
         << "b: " << b;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "\nOutput"
         << endl;
    cout << "a: " << a << "\n"
         << "b: " << b;

    // output
    // a = 30 b = 20
}