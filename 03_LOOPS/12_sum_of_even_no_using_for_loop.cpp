#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    int evenSum = 0;
    for (int i = 0; i <= n; i++)
    {

        if (i % 2 == 0)
        {

            evenSum += i;
            cout<<i;
        }
        i++;
    }
    cout << evenSum;
    return 0;
}