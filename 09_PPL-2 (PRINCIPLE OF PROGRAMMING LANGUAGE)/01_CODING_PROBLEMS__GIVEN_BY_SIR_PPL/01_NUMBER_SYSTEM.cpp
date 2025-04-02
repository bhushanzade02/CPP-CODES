#include <iostream>
using namespace std;

int decTobin(int decNum)
{
    int ans = 0;
    int pow = 1;
    while (decNum > 0)
    {
        int rem = decNum % 2;
        decNum = decNum / 2;
        ans += (rem * pow);
        pow *= 10;
    }
    return ans;
};
int decTOoct(int decNum)

{

    int ans = 0;
    int pow = 1;

    while (decNum > 0)
    {
        int rem = decNum % 8;
        decNum /= 8;
        ans += (rem * pow);
        pow *= 10;
    }
    return ans;
};

int binTodec(int binNum)
{
    int ans = 0;
    int pow = 1;
    while (binNum > 0)
    {
        int rem = binNum % 10;
        ans += (rem * pow);
        binNum = binNum / 10;
        pow *= 2;
    }
    return ans;
};

string decTohex(int n)
{
    string ans = "";
    char hexChar[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (n > 0)
    {
        int rem = n % 16;
        ans = hexChar[rem] + ans;
        n /= 16;
    }
    return ans;
};
int main()
{
    int num;
    int base;

    cout << "ENTER A NUMBER" << endl;
    cin >> num;

    cout << "ENTER A BASE VALUE" << endl;
    cin >> base;

    if (base == 2)
    {
        cout << binTodec(num) << endl;
    }
    else if (base == 8)
    {
        cout << decTOoct(num) << endl;
    }
    else if (base == 16)
    {
        cout << decTohex(num) << endl;
    }
    else if (base == 10)
    {
        cout << num;
    }
}
