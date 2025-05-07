#include <iostream>
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
    bhus.open("D:\\13_CPP-CODES\\09_PPL-2 (PRINCIPLE OF PROGRAMMING LANGUAGE)\\07_PRACTICE_FOR_END_SEM\\bhus.txt");

    while (getline(bhus, str))
    {
        cout << str << endl;
        linecount++;

        charcount += str.size() + 1;
    }
    stringstream sid(str);
    string word;
    while (sid >> word)
    {

        wordcount++;
    }

    cout << "Line count " << linecount << endl;
    cout << "Word Count " << wordcount << endl;
    cout << "Sentence Count " << sentcount << endl;
    cout << " Character count " << charcount << endl;
    return 0;
}