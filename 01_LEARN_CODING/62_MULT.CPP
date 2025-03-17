#include <iostream>
using namespace std;

class A
{
    int n, i;

public:
    void table()
    {
        cout << "ENter number of tabel" << endl;
        cin >> n;
        for (i = 1; i <= 10; i++)
        {
            cout << n << " X " <<i<< " = "  << n * i << endl;
        }
    }
};
main()
{
    A obj;
    obj.table();
}