#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter a no";
    cin >> n;
    bool isPrime = true;
    for (int i = 2; i < n - 1; i++)
    {
        if (n % 2 == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime == true)
    {
        cout << "no is prime";
    }
    else
    {
        cout << "no is not prime no";
    }
    return 0;
}