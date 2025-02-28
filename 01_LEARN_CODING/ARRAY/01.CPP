#include<iostream>
using namespace std;

int main()
{
    int arr[5];
    cout<<"enter a elements"<<endl;

    for(int i =0; i<sizeof(arr)/sizeof(arr[0]);i++){
    cin>>arr[i];
    }

    for(int i =0 ; i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        cout<<arr[i]<<endl;
    }




}