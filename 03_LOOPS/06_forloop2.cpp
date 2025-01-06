#include <iostream>
using namespace std;

int main()
{
    int n;
    int i;
    cout << "enter a number";
    cin >> n;
    for (i = 1; i <= 10; i++)
    {
        cout << n * i  << endl;
    }
    return 0;
}