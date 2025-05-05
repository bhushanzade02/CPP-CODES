// Design ,Develop and test a c++ class to determine
// if the given 4-digit positive integer represents
// a leap year or not
#include <iostream>
using namespace std;

class year
{
public:
    bool leapyear(int y)
    {
        if (y % 400 == 0 && y % 100 == 0 || y % 4 == 0 && y % 100 != 0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    int n;
    cout << "enter a Year " << endl;
    cin >> n;

    year obj;

    if (obj.leapyear(n))
    {
        cout << n << "is a leap Year" << endl;
    }
    else
    {
        cout << n << "is not a leap Year" << endl;
    }
}