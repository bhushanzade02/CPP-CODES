#include <iostream>
using namespace std;

// Binary to Decimal

int bintodec(int decnum)
{
    int ans = 0;
    int pow = 1;
    while (decnum > 0)
    {
        int rem = decnum % 10;

        ans += (rem * pow);
        pow *= 2;
        decnum = decnum / 10;
    }
    return ans;
}

// Octal to decimal
int octtodec(int decnum)
{

    int ans = 0;
    int pow = 1;
    while (decnum > 0)
    {
        int rem = decnum % 8;
        decnum = decnum / 8;
        ans += (rem * pow);
        pow *= 8;
    }
    return ans;
}

// Decimal to Binary
int dectobin(int decnum)
{
    int ans = 0;
    int pow = 1;
    while (decnum > 0)
    {
        int rem = decnum % 2;
        decnum = decnum / 2;
        ans += (rem * pow);
        pow *= 10;
    }
    return ans;
}

// hexadecimal
string dectohex(int n)
{
    string ans = " ";
    char hexadec[] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    while (n > 0)
    {
        int rem = n % 16;
        ans = hexadec[rem] + ans;
        n = n / 16;
    }
    return ans;
}

// Decimal to Octal
int dectooct(int decnum)
{

    int ans = 0;
    int pow = 1;
    while (decnum > 0)
    {
        int rem = decnum % 8;
        decnum = decnum / 8;
        ans += (rem * pow);
        pow *= 10;
    }
    return ans;
};
//

int main()
{
    int num;
    int base;
    cout << "Enter a NUmber " << endl;
    cin >> num >> base;

    if (base == 2)
    {
        cout << dectobin(num);
    }
    if (base == 8)
    {
        cout << dectooct(num);
    }
    if (base == 10)
    {
        cout << "Binary" << bintodec(num);
        cout << "ocatl" << octtodec(num);
    }
    if (base == 10)

    {
        return 0;
    }
    if (base == 16)
    {
        cout << dectohex(num);
    }
}