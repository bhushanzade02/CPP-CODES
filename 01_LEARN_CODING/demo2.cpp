
#include <iostream>
using namespace std;

int findmax(int arr[], int size)
{
    int max_value = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }
    return max_value;
}

int main()
{
    int arr[10];
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "enter the elemts ";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    int max_value=findmax(arr,size);
    cout<<"Max elemet from given array is :"<<max_value<<endl;
    
    return 0;
}