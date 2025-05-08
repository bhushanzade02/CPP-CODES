#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Csort
{

public:
    void sortnumber()
    {
        int n;
        cout << "Enter the Number of elements ";
        cin >> n;

        vector<double> arr(n);
        cout << "Enter the elements" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        char choice;
        cout << "Enter A for asecending and D for descending " << endl;
        cin >> choice;

        if (choice == 'A' || choice == 'a')
        {
            sort(arr.begin(), arr.end());
        }
        else if (choice == 'B' || choice == 'b')
        {
            sort(arr.begin(), arr.end(), greater<double>());
        }

        for (double val : arr)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main()
{
    Csort obj;
    obj.sortnumber();
    return 0;
}