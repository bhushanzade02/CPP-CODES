#include <iomanip>
#include <iostream>
#define MAX 100
using namespace std;
int main()
{

    float ax[MAX + 1], ay[MAX + 1], nr, dr, x, y = 0;

    int n;
    cout << "enter th value of n " << endl;
    cin >> n;

    cout << "Enter the set of values" << endl;
    for (int i = 0; i <= n; i++)
    {
        cin >> ax[i] >> ay[i];
    }
    
    cout << "enter the value of x for which"
         << "y value  wanted" << endl;
    cin >> x;
    cout << fixed;

    for (int i = 0; i <= n; i++)
    {

        nr = dr = 1;
        for (int j = 0; j <= n; j++)
        {
            if (j != i)
            {
                nr *= x - ax[j];
                dr *= ax[i] - ax[j];
            }
        }

        y += (nr / dr) * ay[i];
    }

    cout << "when x = " << setw(4) << setprecision(1) << x << "y = " << setw(4) << setprecision(1) << y << endl;
    return 0;
}