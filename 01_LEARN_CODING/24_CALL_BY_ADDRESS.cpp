
#include <iostream>
using namespace std;
int ChangeValue(int *p)
{
    *p = *p + 10;
    cout << *p << endl;
}

int main()
{
    int num = 100;
    cout << num <<endl;
    ChangeValue(&num);
    cout<<num<<endl;

    return 0;
}