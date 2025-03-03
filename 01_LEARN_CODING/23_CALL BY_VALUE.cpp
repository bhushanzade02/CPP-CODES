
#include <iostream>

using namespace std;
int changeValue(int num)
{
    num = num + 10;
    cout<< num<<endl;
}

int main()
{
    int num = 100;
    changeValue(num);
    cout << num;

    return 0;
}