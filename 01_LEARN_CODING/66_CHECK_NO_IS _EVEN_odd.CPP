#include<iostream>
using namespace std;


class Num{
    int n ;
    public:
    void input()
    {
        cout<<"eneter a number"<<endl;
        cin>>n;

    }
    void show()
    {
        if (n%2==0?cout<<"EVEN":cout<<"ODD");
    }
};

main()
{
    Num obj;
    obj.input();
    obj.show();
}