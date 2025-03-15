#include <iostream>
using namespace std;

template <class T>

void show(T a, T b)
{
    cout << "A" << a << ends << "B" << b << endl;
}
int main()
{
    int p = 10, q = 20;
    char m = 'b', n = 's';
    float s = 10.4, f = 12.3;
    show(p, q);
    show(m, n);
    show(s, f);
};