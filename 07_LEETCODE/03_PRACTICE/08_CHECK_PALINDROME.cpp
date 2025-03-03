
#include <iostream>
#include <string>
using namespace std;
int main()
{

    string s = "aabaa";
    string rev = string(s.rbegin(), s.rend());
    if (s == rev)
    {
        cout << "it is paliderome" << endl;
    }
    else
    {
        cout << "it is not palindrome" << endl;
    }

    return 0;
}