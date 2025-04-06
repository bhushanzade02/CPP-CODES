#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    ifstream filename;
    char ch;
    int sizeinbyte = 0;
    filename.open("bhushan.txt");
    while (filename.get(ch))
    {
        sizeinbyte++;
    }

    filename.close();
    cout << sizeinbyte;
    return 0;
}