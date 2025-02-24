#include <iostream>
using namespace std;
main()
{
    int arr[5];
    cout << "enter array elemenst " << endl;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i]  << endl;
    }

    for(int i=5;i>=0;--i)
        {
            cout<<arr[i]<<endl;
        }