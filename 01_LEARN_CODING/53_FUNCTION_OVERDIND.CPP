#include <iostream>
using namespace std;

class A
{
public:
    void func()
    {
        cout << "BHUSHAN" << endl;
    }
};

class B : public A
{
    void func()
    {
        cout << "ZADE" << endl;
    }
};

int main()
{
    B obj;
    obj.A::func();

}