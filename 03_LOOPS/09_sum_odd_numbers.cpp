#include <iostream>
using namespace std;

int main()
{

    int n = 10;
    int sum = 0;
    for (int i = 1; i <= n; i = i + 2)
    {
        sum = sum + i;
        cout<<i<<endl;
    }
    cout << sum;
    return 0;
}
