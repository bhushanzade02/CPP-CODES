#include <iostream>
#include <cmath>
using namespace std;

class A
{
public:
    int find_e_x(int x)
    {

        double ex = 1;
        double tex = 1.0;
        double n = 1;
        while (abs(tex) > 1e-8)
        {
            tex *= x / n;
            ex += tex;
            n++;
        }

        cout << ex;
    }
};
int main()
{

    A obj;
    obj.find_e_x(3);
    return 0;
}