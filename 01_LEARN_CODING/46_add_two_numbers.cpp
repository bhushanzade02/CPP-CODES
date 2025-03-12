#include <iostream>
using namespace std;
class A
{
public:
    int multiply(int x, int y)
    {
        cout << x * y << endl;
    }
    int addTwo(int x, int y)
    {
        cout << x + y << endl;
    }
};
int main()
{
    A obj;

    obj.addTwo(10, 20);
    obj.multiply(3, 2);
    return 0;
}