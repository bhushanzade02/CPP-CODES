/*3. Design, develop and test CPP code for reading a text file and displaying
statistics such as number of lines, number of words, number of characters
and number of sentences contained in that file. The number of characters
should include characters like white spaces and text control characters.
Test case:
Input: The file contains the following text:
I am a C programmer. My programs work great and they hardly
have any logical errors. Pointer is my favourite data type.
Output:
number of lines : 2
number of words: 22
number of characters: 121
number of sentences: 3
*/

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
    int charcount = 0;
    int sentcount = 0;
    int wordcount = 0;

    bhus.open("D:\\13_CPP-CODES\\09_PPL-2 (PRINCIPLE OF PROGRAMMING LANGUAGE)\\05_PRACTICE SESSION\\bhush.txt");

    while (getline(bhus, str))
    {

        cout << str << endl;
        linecount++;
        charcount += str.size() + 1;

        for (char ch : str)
        {
            if (ch == '.' || ch == '?' || ch == '!')
                sentcount++;
        }
        stringstream sid(str);
        string word;
        while (sid >> word)
        {
            wordcount++;
        }
    }

    cout << linecount << endl;
    cout << charcount << endl;
    cout << sentcount << endl;
    cout << wordcount << endl;
}