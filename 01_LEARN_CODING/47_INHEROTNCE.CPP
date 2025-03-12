#include <iostream>
using namespace std;

class Father
{
protected:
    string surname = "Zade";
};
class Son1 : Father
{
    string name = "Sanjay";

public:
    void show()
    {
        cout << name << " " << surname << endl;
    }
};
class Son2 : Father
{
    string name = "Ajay";

public:
    void display()
    {
        cout << name << " " << surname << endl;
    }
};
int main()
{
    Son1 s1;
    Son2 s2;
    s1.show();
    s2.display();
}