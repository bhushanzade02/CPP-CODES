#include <iostream>
using namespace std;
main()
{

    float arr[5];
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        cout<<"your enterd elemnts are "<<arr[i]<<endl;
    }
    return 0;
    

}