#include <iostream>
using namespace std;
class CSorter
{
    public:
    int sort_ab()
    {
        int n;
        cout << "enter number of elements" << endl;
        cin >> n;

        double a[100];
        cout << "enter elements" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        char ch;

        cout << "you HAVE TO CHOICES A FOR ASCENIDNG" << endl;
        cout << "you HAVE TO CHOICES B FOR DESCENIDNG" << endl;
        cin >> ch;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (ch == 'A' && a[j] > a[j + 1])
                {
                    swap(a[j], a[j + 1]);
                }
                else if (ch == 'B' && a[j] < a[j + 1])
                {
                    swap(a[j], a[j + 1]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << endl;
        }
    }
};

int main()
{

    CSorter obj;
    obj.sort_ab();
    return 0;
}
