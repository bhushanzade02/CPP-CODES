#include "cmplxbz.hpp"
using namespace std;

// Constructor
cmplxbz::cmplxbz()
{
    real = 0;
    img = 0;
    cout << "In cmplxbz default constructor ";
}

// Display function
void cmplxbz::display()
{
    cout << this->real;

    if (this->img > 0)
    {
        cout << " + ";
    }
    else
        cout << "";
    cout << this->img << "i" << std::endl;
}

cmplxbz cmplxbz::add(cmplxbz y)
{
    cmplxbz c;
    c.real = this->real + y.real;
    c.img = this->img + y.img;
    return c;
}

// Subtraction
cmplxbz cmplxbz::subtract(cmplxbz y)
{
    cmplxbz c;
    c.real = this->real - y.real;
    c.img = this->img - y.img;
    return c;
}
