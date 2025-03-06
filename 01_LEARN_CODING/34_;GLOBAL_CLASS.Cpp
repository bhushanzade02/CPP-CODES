#include <iostream>
using namespace std;
class A
{
protected:
    int a, b;

public:
    void input()
    {
        cout << "enter Two Numbers";
        cin >> a >> b;
    }
    void show()
    {
        cout << a << " " << b<<endl;
    }
};

class B : public A
{
public:
    void disp()
    {
        cout << a << " " << b;
    }

};
 int main()
{
    A obj;
    B obj2;
    // obj.input();
    // obj.show();
    obj2.input();
    obj2.show();
    obj2.disp();
}