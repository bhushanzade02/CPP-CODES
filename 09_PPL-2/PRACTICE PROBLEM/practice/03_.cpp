#include <iostream>
#include <fstream>
using namespace std;
int main()
{

    ifstream sid;
    string str;
    sid.open("D:\\13_CPP-CODES\\09_PPL-2\\PRACTICE PROBLEM\\practice\\bhushan.txt");
    while (getline(sid, str))
    {
        cout << str;
    }

    sid.close();
}
