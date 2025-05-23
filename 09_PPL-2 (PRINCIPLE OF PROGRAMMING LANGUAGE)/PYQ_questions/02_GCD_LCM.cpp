#include <iostream>
using namespace std;

class NumberOperation
{
public:
    int gcd(int x, int y)
    {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }

    int lcm(int x, int y)
    {
        if (y == 0)
            return x;
        return (x * y) / gcd(x, y);
    }
};

int main()
{
    int num1, num2;
    cout << "ENter num1 and num2 " << endl;
    cin >> num1 >> num2;

    NumberOperation obj;
    int result = obj.gcd(num1, num2);
    cout << result << endl;


    int result1 = obj.lcm(num1, num2);
    cout << result1 << endl;
}