#include "iostream"
using namespace std;

class A
{
public:
    class B
    {
        int a, b;

    public:
        void input()
        {
            cout << "ENter two element";
            cin >> a >> b;
        }
        void show()
        {
            cout << a << " " << b;
        }
    };
};
int main()
{
    A::B obj;
    obj.input();
    obj.show();
    
}