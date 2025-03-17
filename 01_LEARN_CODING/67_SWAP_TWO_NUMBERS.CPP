#include <iostream>
using namespace std;

class Swap
{
    int a, b;

public:
    void input()
    {
        cout << "Value of A" << endl;
        cin >> a;
        cout << "Value of B" << endl;
        cin >> b;
    }
    void show()
    {

        cout << "After Swapping" << endl;
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        cout << "A : " << a << " B: " << b << endl;
    }
};



main()
{
    Swap obj;
    obj.input();
    obj.show();

}