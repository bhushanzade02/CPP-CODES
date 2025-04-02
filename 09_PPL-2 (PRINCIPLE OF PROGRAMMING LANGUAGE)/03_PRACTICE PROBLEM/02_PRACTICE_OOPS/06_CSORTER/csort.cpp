#include "csort.hpp"
#include <iostream>
using namespace std;

int Csorter::bhus(int n)
{

    double a[100];
    cout << "Enter a elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    char ch;
    cout << "enter A for ascending" << endl;
    cout << "enter B for descending" << endl;
    cin >> ch;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (ch == 'A' && a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
            else if (ch == 'D' && a[j] < a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}