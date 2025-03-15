#include <iostream>
using namespace std;

class A
{
    int n;

public:
    void input1()
    {
        cout << "ENTer a VAlue Of n";
        cin >> n;
    }
    void show1()
    {
        cout << " VAlue of n: " << n << endl;
    }
};

class B : virtual public A
{
};
class C : virtual public A
{
};
class D : public B, public C
{
};

int main()
{
    A obj1;
    B obj2;
    C obj3;
    D obj4;
    // obj1.input1();
    // obj1.show1();

    // obj1.input1();
    // obj2.show1();

    obj4.input1();
    obj4.show1();
};