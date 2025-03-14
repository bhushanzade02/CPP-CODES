#include <iostream>
using namespace std;

class Base1
{
    int a, b, c;

public:
    void input1()
    {
        cout << "enter a value of a b c ";
        cin >> a >> b;
    }
    void show1()
    {

        c = a + b;
        cout << " value of addion" << c;
    }
};
class Base2
{
    int a, b, c;

public:
    void input2()
    {
        cout << "enter a value of a b c ";
        cin >> a >> b;
    }
    void show2()
    {

        c = a + b;
        cout << " value of addion" << c;
    }
};

class derive : public Base1, public Base2
{

    int a, b, c;

public:
    void d1()
    {
        cout << "hello" << endl;
    }
};

int main()
{
    derive obj;
    obj.input1();
    obj.show1();
}