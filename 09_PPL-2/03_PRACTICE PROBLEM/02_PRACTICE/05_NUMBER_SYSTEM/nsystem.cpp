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


int Numbersystem::