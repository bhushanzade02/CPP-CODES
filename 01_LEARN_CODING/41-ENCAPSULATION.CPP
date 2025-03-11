#include <iostream>
using namespace std;
class Encap
{
private:
    int age;
    void show()
    {
        cout << "SIddhi" << endl;
    }

public:
    string name;
    void setvalue(int x)
    {
        show();
        age = x;
        cout << age << endl;
    }
};

int main()
{
    Encap obj;
    obj.name = "BHUhan";
    obj.setvalue(34);
}