
#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    cout << fact << endl;

    return 0;
}