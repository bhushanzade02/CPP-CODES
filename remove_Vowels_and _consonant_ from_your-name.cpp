#include <iostream>
#include <string>
using namespace std;

int main()
{

    string a;
    cout << "Enter Your Name " << endl;
    cin >> a;

    int n = a.size();
    string ans = "";
    string ans1 = "";

    for (char c : a)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            ans += c;
        }
    }

    cout << a << " contains This Vowels :  " << ans << "\n";

    for (char c : a)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            continue;
        }
        ans1 += c;
    }
    cout << a << " contains This consonant :" << ans1 << endl;
}