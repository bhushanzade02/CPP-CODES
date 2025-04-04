#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream filename;
    string str;
    filename.open("bhushan.txt");
    while (getline(filename, str))
    {
        cout<<str;
        filename.close();
        return 0;
    }
}