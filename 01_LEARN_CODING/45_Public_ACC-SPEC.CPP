#include <iostream>
using namespace std;
class A
{
public:
    int a;
    void show();
};
void A::show()
{
    a = 10;
    cout << "Outuside A cLASS" << a << endl;
}
int main()
{
    A obj;
    obj.show();
    obj.a = 20;
    cout << "Outside the Classs" << obj.a;
}