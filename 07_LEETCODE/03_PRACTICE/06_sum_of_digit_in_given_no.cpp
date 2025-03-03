
#include <iostream>
using namespace std;
int main()
{
    // calculat the sum of given number

    int n = 123;
    int ans = 0;
    while (n > 0)
    {
        ans += n % 10;
        n /= 10;
    }

    cout << ans << endl;

    return 0;
}