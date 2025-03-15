#include <iostream>
using namespace std;
class car
{

public:
    bool startEngine;
    void start()
    {
        startEngine = true;
        cout << "Engine started" << endl;
    }

    void drive()
    {
        if (startEngine)
        {
            cout << "you are ready to drive " << endl;
        }
        else
        {
            cout << "you can't Drive A Car";
        }
    }
};

int main()
{
    car c;
    c.start();
    c.drive();
}