#include<iostream>
using namespace std ;

class A
{
    char c;
    public:
    void input()
    {
        cout<<"ENter any cahracter"<<endl;
        cin>>c;
    }

    void output()
    {
        cout<<"ASCII value is : "<<int(c)<<endl;
    }
};





int main()
{
    A obj;
    obj.input();
    obj.output();
};
