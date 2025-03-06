#include <iostream>
using namespace std;

class A
{
public:
    int a;
    A()
    {
        a = 10;
    }
    void show()
    {
        cout << a;
    }
};
int main()
{
    A obj = A();
    obj.show();
}