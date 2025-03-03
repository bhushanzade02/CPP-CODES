
#include <iostream>

using namespace std;

int fact(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * fact(num - 1);
    }
}
int main()
{
    int n = 4;
    int result = fact(n);
    cout << "The factorial of " << n << " is :" << result << endl;

    return 0;
}