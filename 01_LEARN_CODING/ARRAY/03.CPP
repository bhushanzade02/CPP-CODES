#include <iostream>
using namespace std;
main()
{

    char arr[5];
    for(int i =0 ; i<sizeof(arr)/sizeof(arr[0]);i++)
    {
cin>>arr[i];
    }
    for(int i=0 ;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        cout<<arr[i];
    }
    return 0;
}