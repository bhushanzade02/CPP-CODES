#include "root.hpp"
#include <iostream>
using namespace std;

int Root::find_root(int a, int b, int c)
{
    int delta = ((b * b) - (4 * a * c));
    if (delta > 0)
    {
        cout << "Roots are Real And Distinct" << endl;
    }

    else if (delta == 0)
    {
        cout << "Root are real and Equal" << endl;
    }
    else
    {
        cout << "roots are Imaginary" << endl;
    }

}
