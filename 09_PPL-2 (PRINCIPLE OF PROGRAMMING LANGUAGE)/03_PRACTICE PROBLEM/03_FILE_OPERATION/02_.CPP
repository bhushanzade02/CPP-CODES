#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream bhus;
    bhus.open("D:\\13_CPP-CODES\\09_PPL-2\\PRACTICE PROBLEM\\practice\\bhushan.txt");
    bhus << ("Bhushan is Good boy");

    bhus.close();
}
