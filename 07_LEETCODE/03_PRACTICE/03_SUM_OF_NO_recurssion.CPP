
#include <iostream>
using namespace std;
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sum(n - 1);
}
int main()
{
    int result = sum(5);
    cout << "THE usum of NUmber upto:" << result << endl;

    return 0;
}
