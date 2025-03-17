#include<iostream>
using namespace std;

class Max{
    int a,b;
    public:
    void input()
    {
        cout<<"enter A value"<<endl;
        cin>>a;
        cout<<"ENter B value"<<endl;
        cin>>b;
    }
    void show()
    {
        cout<<"MAx no is "<<endl;
        if((a>b)?cout<<a:cout<<b);
    }
};
main()
{

    Max A;
    A.input();
    A.show();
    

}