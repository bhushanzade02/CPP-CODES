#include <iostream>
using namespace std;

class A
{
    int a = 10, b = 30;

public:
    void show()
    {
        cout << a << "    " << b<<endl;
    }
    friend class B;
};
class B
{
public:
    void add(A ref)
    {
        int add = ref.a + ref.b;
        cout << "SUM : " << add;
    }
};
main()
{
    A obj1;
    B obj2;
    obj1.show();
    obj2.add(obj1);
}
