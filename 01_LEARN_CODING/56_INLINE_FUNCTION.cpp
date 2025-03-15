#include <iostream>
using namespace std;
inline int func(int a, int b, int c)
{
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
};
main()
{
    int value = func(29,38,12);
    cout << value;
}