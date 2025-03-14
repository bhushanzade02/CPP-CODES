#include <iostream>
using namespace std;
class Base
{
private:
    int a, b;

public:
    void input()
    {
        cout << "enter values of a and b";
        cin >> a >> b;
    }
    void show()
    {
        cout << "a :" << a << " b :" << b << endl;
    }
};

class derived : public Base
{
private:
    int m, n;

public:
    void getdata()
    {
        cout << "enter a values for M and N" << endl;
        cin >> m >> n;
    }
    void display()
    {
        cout << "M:" << m << " N: " << n << endl;
    }
};

int main()
{
    Base ob1;
 ob1.input();
 ob1.show();


 derived ob2;
 ob2.input();
 ob2.getdata();
 ob2.display();

}
