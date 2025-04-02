#include <iostream>
using namespace std;
int dectobin(int decnum)
{
    int ans = 0;
    int pow = 1;
    while (decnum > 0)
    {
        int rem = decnum % 2;
        decnum = decnum / 2;
        ans += (rem * pow);
        pow = pow * 10;
    }
    return ans;
}

int dectooctal(int decnum)
{
    int ans = 0;
    int pow = 1;
    while (decnum > 0)
    {
        int rem = decnum % 8;
        decnum = decnum / 8;
        ans += (rem * pow);
        pow = pow * 10;
    }
    return ans;
}

int binarytodec(int binnum)
{
    int ans = 0;
    int pow = 1;
    while (binnum > 0)
    {
        int rem = binnum % 10;
        ans += (rem * pow);
        binnum = binnum / 10;

        pow *= 2;
    }
    return ans;
}

string dectohex(int num)
{

    string ans = "";
    char hexchar[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (num > 0)
    {
        int rem = num % 16;
        ans = hexchar[rem] + ans;
        num /= 10;
    }
    return ans;
}

int main()
{

    int n;
    cout << "enter a Number" << endl;
    cin >> n;
    int base;
    cout << "Eenter base value which youwant to convert" << endl;
    cin >> base;
    if (base == 2)
    {
        cout << dectobin(n);
    }
    else if (base == 8)
    {
        cout << dectooctal(n);
    }
    else if (base == 10)
    {
        cout << binarytodec(n);
    }
    else if (base == 16)
    {
        cout << dectohex(n);
    }
}