#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    ifstream bhus;
    string str;
    int linecount = 0;
    int wordcount = 0;
    int charcount = 0;
    int sentcount = 0;
    bhus.open("D:\\13_CPP-CODES\\09_PPL-2\\PRACTICE PROBLEM\\01_PRACTICE\\bhushan.txt");

        

    while (getline(bhus, str))    {
        cout << str << endl;
        linecount++;
        charcount += str.size() + 1;

        for (char ch : str)
        {
            if (ch == '.' || ch == '?' || ch == '!')
            {
                sentcount++;
            }
        }
        stringstream sid(str);
        string word;
        while (sid >> word)
        {
            wordcount++;
        }
    }

    cout << linecount << endl;
    cout << wordcount << endl;
    cout << charcount << endl;
    cout << sentcount << endl;
    bhus.close();
}