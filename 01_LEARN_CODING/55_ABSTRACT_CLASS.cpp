#include <iostream>
using namespace std;

class A
{
public:
    virtual void show() = 0;
    void disp()
    {
        cout << "HI I am bASE Class" << endl;
    }
};
class B : public A
{
public:
    void show()
    {
        cout << "HI I am Derive CLASS" << endl;
    }
};

int main()
{
    // B obj;
    // obj.disp();
    // obj.show();

    A *p;
    B obj;
    p = &obj;
    p->show();
}