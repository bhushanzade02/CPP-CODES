#include <iostream>
#include <string.h>
using namespace std;
main()
{
    char str[] = "Bhushan";
    char str2[10];
    char str3[10] = "zade";

    // int l=strlen(str); len of string
    // cout<<strrev(str)<<endl; reverse the string
    // cout << "first before" << str << endl;
    // strcpy(str2, str);
    // cout << "after str 1 to str 2" << str2 << endl;


    strcat(str,str3);
    cout<<str<<endl;
}