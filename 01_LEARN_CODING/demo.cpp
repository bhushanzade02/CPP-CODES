
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
//     vector<int>arr={13,3,2,3,2,3,2};
// //  int arr[]={13,3,2,3,2,3,2};
// vector<int>result;
//  int result =max(arr.begin(),arr.end());

// cout<<result<<endl;

int arr[]={1,35,1,32,4,2,3,23,23};

int max_value=*max_element(arr,arr+sizeof(arr)/sizeof(arr[0]));

cout<<max_value<<endl;
    return 0;
}