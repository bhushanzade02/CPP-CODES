#include <iostream>
using namespace std;
int main()
{

    char ch;
    cout << "enter a character ";
    cin >> ch;
    if(ch>='A' && ch<='Z')
    {
        cout<<"Upper case";
    }
    else{
        cout<<"Lower Case";
    }

    return 0;
}