#include <iostream>
using namespace std;

class Base
{
protected:
    int a, b;

public:
    void show()
    {
        a = 10;
        b = 20;
        cout << a << ends << b;
    }
};
class Derived : public Base
{
public:
    void disp()
    {
        a = 30;
        b = 39;
        cout << a << ends << b;
    }
};
int main()
{
    Derived obj;
    obj.disp();
    obj.show();
}