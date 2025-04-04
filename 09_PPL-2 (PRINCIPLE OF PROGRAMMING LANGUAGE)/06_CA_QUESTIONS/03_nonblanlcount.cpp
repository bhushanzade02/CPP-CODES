#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char ch;
    ifstream filename;
    int nonblankcount = 0;
    filename.open("bhushan.txt");
    while (filename.get(ch))
    {
        cout << ch ;
        if (ch != ' ' && ch != '\t' && ch != '\n')
        {
            nonblankcount++;
        }
    }
    filename.close();
    cout <<'\n'<< nonblankcount;
    return 0;
}
