#include<iostream>
using namespace std;

int main()
{
    int a=5;
    int b=10;
    // a=a+b;
    // b=a-b;
    // a=a-b;

    a=a^b;
    b=a^b;
    a=a^b;

    cout<<"value of a"<<a<<endl;
    cout<<"value of b"<<b<<endl;


}