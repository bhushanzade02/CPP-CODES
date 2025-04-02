#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream bhus;
    ofstream sid;
    char str;
    bhus.open("D:\\13_CPP-CODES\\09_PPL-2\\PRACTICE PROBLEM\\practice\\bhushan.txt");
    sid.open("D:\\13_CPP-CODES\\09_PPL-2\\PRACTICE PROBLEM\\practice\\sid.txt");
    while (bhus.get(str))
    {
        sid.put(str);
    }
    cout << "Copied" << endl;
    bhus.close();
    sid.close();
}