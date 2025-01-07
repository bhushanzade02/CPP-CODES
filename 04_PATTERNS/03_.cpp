#include <iostream>
using namespace std;

int main()
{

    int n = 3;
    for (int i = 1; i <= n; i++)
    {

        int sum = 1;
        for (int j = 1; j <= 3; j++)
        {
            sum = sum + j;
            cout << sum <<" ";
            sum++;
        }
        cout << endl;
    }

    return 0;
}