#include <iostream>
using namespace std;

template <class T>
class show
{
    T a, b;

public:
    show(T p, T q)
    {
        a = p;
        b = q;
    }
    void show()
    {
        cout << "A:" << A << " " << "B :" << b << endl;
    }
};  
void main()
{
    show<int> ob(10, 12);
    ob.show();
}