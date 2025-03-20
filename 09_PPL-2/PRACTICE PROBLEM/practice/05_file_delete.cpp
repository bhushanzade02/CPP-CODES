#include <iostream>
using namespace std;
int main()
{
    int value = remove("D:\\13_CPP-CODES\\09_PPL-2\\PRACTICE PROBLEM\\practice\\sid.txt");
    if (value == 0)
    {
        cout << "FIle deleted";
    }
    else
    {
        cout << "FIle Not deleted";
    }
}
