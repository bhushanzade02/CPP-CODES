#include <iostream>
using namespace std;
class Base
{
private:
    int a;

public:
    void input()

    {
        cout << "enter a value of a ";
        cin >> a;
    }
    void show()
    {
        cout << "value of A:" << a;
    }
};

class derived1 : public Base
{
private:
    int m;

public:
    void input1()
    {
        cout << "enter a value of M" << endl;
        cin >> m;
    }
    void show1()
    {
        cout << "Value of M:" << m;
    }
};
class derived2 : public derived1
{
    int n;

public:
    void input2()
    {
        cout << "entr a value of N" << endl;
        cin >> n;
    }
    void show2()
    {
        cout << n;
    }
};
int main()
{
    derived2 obj;
    obj.input();
    obj.show();
    Base obj2;
    obj2.input();
    obj2.show();
}