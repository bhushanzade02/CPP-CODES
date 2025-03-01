
#include <iostream>
using namespace std;
int main()
{
 int arr[2][2];
 cout<<"enter a  elemnts "<<endl;
 for(int i =0 ; i<4 ;i++)
 {
    for(int j=0 ;j<4;j++)
    {
        cin>>arr[i][j];
    }
 }

 for(int i =0 ;i<4;i++)
 {
    for(int j=0 ; j<4;j++)
    {

        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
 }
    return 0;
}