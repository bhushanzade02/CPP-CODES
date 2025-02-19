#include <iostream>
#include <typeinfo>

using namespace std;
int main()
{
    int a = 10;
    double b = 3.14;
    char c = 'A';

    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;

    // IMPLICIT TYPECASTING
    double a2 = a;
    cout << a2 << endl;
    int b2 = b;
    cout << b2 << endl;

    // EXPLICITE TYPE CASTING
    double a3 = (double)a;
    cout << a2 << endl;
    cout << typeid(a3).name() << endl;

    int b3 = (int)b;
    cout << b3 << endl;
    cout << typeid(b3).name() << endl;
}
