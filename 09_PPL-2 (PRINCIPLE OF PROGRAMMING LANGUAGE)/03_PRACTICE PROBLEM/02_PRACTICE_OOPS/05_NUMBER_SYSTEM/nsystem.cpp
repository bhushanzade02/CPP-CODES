#include "nsystem.hpp"
#include <iostream>
using namespace std;
int Numbersystem::dectobin(int decnum)
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

int Numbersystem::dectooctal(int decnum)
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
}

int Numbersystem::bintodec(int binnum)
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
string  Numbersystem::dectohex(int n)
{
    string ans = " ";
    char hexchar[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (n > 0)
    {
        int rem = n % 16;
        ans = hexchar[rem] + ans;
        n /= 16;
    }
    return ans;
}