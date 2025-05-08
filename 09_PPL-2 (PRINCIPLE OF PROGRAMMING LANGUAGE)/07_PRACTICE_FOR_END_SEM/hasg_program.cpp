#include <iostream>
#include <string>
using namespace std;

string removeLeadingZeros(string s)
{
    size_t i = 0;
    while (i < s.length() && s[i] == '0')
        ++i;
    return (i == s.length()) ? "0" : s.substr(i);
}

string removeTrailingZeros(string s)
{
    size_t i = s.length();
    while (i > 0 && s[i - 1] == '0')
        --i;
    return (i == 0) ? "0" : s.substr(0, i);
}

int main()
{
    string input;
    cout << "ENter a Number ";
    cin >> input;

    size_t dotPos = input.find('.');
    string F = input.substr(0, dotPos), I = input.substr(dotPos + 1);

    string J = removeTrailingZeros(F), G = removeLeadingZeros(I);

    cout << G << string(max(0, 5 - (int)G.length()), '#') << "." << J << endl;
    return 0;
}
