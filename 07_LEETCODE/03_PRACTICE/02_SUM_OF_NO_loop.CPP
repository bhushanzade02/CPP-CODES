
#include <iostream>
using namespace std;
int main()
{
 
    int n = 5;
    int ans = 0;
    for (int i = n; i > 0; --i)
    {
        ans += i;
    }

    cout << ans;
    return 0;
}