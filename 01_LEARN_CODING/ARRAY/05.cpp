#include <iostream>
using namespace std;
main()
{

    char arr[5];
    for (int i = 0; i < 10; i++)
    {
        int temp;
        cin >> temp;

        if (i < 5)
        {
            arr[i] = temp;
        }
    }
    


for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
{
    cout << arr[i]<<" ";
}
cout<<endl;
return 0;
}