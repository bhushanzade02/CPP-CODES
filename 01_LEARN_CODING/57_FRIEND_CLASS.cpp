#include <iostream>
using namespace std;

class Ankit;
class Ankush
{
private:
    int money = 20;
    friend void rohit(Ankit, Ankush);
};
class Ankit
{
private:
    int money = 10;
    friend void rohit(Ankit, Ankush);
};

void rohit(Ankit r1, Ankush r2)
{

    cout << "SUM :" << r1.money + r2.money << endl;
};

main()
{
    Ankush obj1;
    Ankit obj2;
    rohit(obj2, obj1);
}
