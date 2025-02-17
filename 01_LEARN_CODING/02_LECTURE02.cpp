// if you want to acces the global variabe then used scope resolution 

#include<iostream>
using namespace std ;
int num =100;
main()
{
    int num =10;
    cout<<::num<<endl;
    cout<<num;
}