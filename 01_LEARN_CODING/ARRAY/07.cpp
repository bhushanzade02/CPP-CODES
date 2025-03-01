#include <iostream>
#include <string>
using namespace std;
int main()
{

    int num[5];
    cout << "Enter a number " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> num[i];
    }
    for(int i=0; i<sizeof(num)/sizeof(num[0]);i++){
        cout<<"your enterd NUm is "<<i<<endl;
    cout << num[i]<< endl;}

    return 0;
}