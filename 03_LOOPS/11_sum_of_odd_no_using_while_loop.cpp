#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    int i = 1;
    int oddSum = 0;
    while (i <= n)
    {
        if (i % 2 != 0)
        {
            oddSum += i;
        }
        i++;
    }
    cout << oddSum;
    return 0;
}