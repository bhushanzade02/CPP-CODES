#include <iostream>
using namespace std;
class A
{
    int a;
    static int b;

public:
    A(int X, int Y)
    {
        a = X, b = Y;
    }
    void show()
    {
        cout << a << " " << b;
    }
    static void disp()
    {
        cout<<b;
    }
};

int A ::b=0;
main()
{
    A obj(10,20),obj1(20,30);
    obj.show();
    obj1.show();
    A::disp();
    obj.show();
}