#include <iostream>
using namespace std;

class test
{
    int a, b;

public:
    test()
    {
        cout << "enter a Valurs";
        cin >> a >> b;
        cout << a << " " << b << endl;
    }
    test(int x, int y)
    {
        a = x;
        b = y;
        cout << a << " " << b<<endl;
    }
    test(test &obj)
    {
        a = obj.a;
        b = obj.b;
        cout << a << " " << b;
    }
};
int main()
{
    test ob;
    test ob2(10,200);
    // test ob3(ob2);
    test ob3(ob);


}