#include <iostream>
using namespace std;

class Leap
{
    int y;

public:
    void leapyear()
    {
        cout << "enter a leap year" << endl;
        cin >> y;
        if (y % 400 == 0 && y % 100 == 0 || y % 4 == 0 && y % 100 != 0 ? cout << "Leap year" : cout << "NOt a leap year")
            ;
    }
};

main()
{
    Leap Obj;
    Obj.leapyear();
}