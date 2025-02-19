#include<iostream>
using namespace std;

int main(){
    int pwd=2371;
    int mypwd;
    cout<<"enter your password";
    cin>>mypwd;


    while(pwd>0)
    {
    if(pwd!=mypwd)
        {
            cout<<"enter your password ";
            cin>>mypwd;
        }
        else{
            cout<<"unlocked";
            break;
        }
    }
}