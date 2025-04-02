#include <iostream>
using namespace std;
int main()
{
    int n = 6;
    bool isPrime = true;
    for (int i = 2; i < n - 1; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime == true)
    {
        cout << "The Number is Prime";
    }
    else
    {
        cout << "Number is Not prime ";
    }

    return 0;
}