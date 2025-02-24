#include <iostream>
using namespace std;
main()
{
    char myName[20];
    cout<<"Enter Your Name"<<endl;
    gets(myName);
    puts(myName);



    string myAddress;
    cout<<"Enter Your Address"<<endl;
    getline(cin,myAddress);
    cout<<"Full Address"<<myAddress<<endl;

}