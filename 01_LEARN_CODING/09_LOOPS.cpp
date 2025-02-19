#include <iostream>
using namespace std;

int main()
{
    int a = 1;
    for (int i = 1; i < 100; i++)
    {
        cout << "bhushan" << endl;
    }

    for (int j = 1; j < 100; j++)
    {
        if (j % 2 == 0)
        {
            cout << j << endl;
        }
    }

    do
    {
        cout << a << endl;
        ++a;
    } while (a < 0);
}