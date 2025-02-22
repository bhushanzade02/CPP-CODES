#include<iostream>
using namespace std;
int main()
{
    int age;
    cout<<"enter your age"<<endl;
    cin>>age;


    if(age>18)
    {
        if(age>18 && age <58)
        {
            cout<<"you can work for company"<<endl;
        }
        else{
            cout<<"you are not eligible "<<endl;
        }
    }
    else{
     cout<<"your are minor"<<endl;
    }

}