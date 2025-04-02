#include "root.hpp"
#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter a b c values" << endl;
    cin >> a >> b >> c;
    Root obj;
    obj.find_root(a, b, c);
}
