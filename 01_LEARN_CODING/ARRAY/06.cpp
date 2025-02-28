
// 6. Read five integers from the user and add them if the addition is greater than
//  10 divide the addition by 2 else divide the addition by 3 and print the answer.

#include <iostream>
using namespace std;
int main()
{

    int arr[5];
    int sum = 0;
    int result = 0;
    
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cin >> arr[i];
    }


    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        sum += arr[i];
    }
cout<<"Total sum is "<<sum<<endl;
    if (sum > 10)
    {
        result = sum / 2;
    }
    else
    {
        result = sum / 3;
    }
    cout << result << endl;

    return 0;
}