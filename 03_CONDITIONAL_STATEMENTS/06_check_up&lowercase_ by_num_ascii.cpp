#include <iostream>
using namespace std;

int main()
{
    char ch;
    cout << "enter a character";
    cin >> ch;
    if (ch >= 60 && ch <= 90)
    {
        cout << "uppercase";
    }
    else
    {
        cout << "lowercase";
    }
    return 0;
}