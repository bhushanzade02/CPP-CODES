#include "comp.hpp"
#include <iostream>
using namespace std;

// construtor
Complex::Complex()
{
    real = 0;
    img = 0;
}

void Complex::display()
{

    cout << real;
    if (img > 0)
    {
        cout << "+" << img << "i" << endl;
    }
    else
    {
        cout << "-" << -img << "i" << endl;
    }
}

Complex Complex::add(Complex a)
{
    cout << "\nADDITION" << endl;
    Complex c;
    c.real = this->real + a.real;
    c.img = this->img + a.img;
    return c;
}

Complex Complex::sub(Complex a)
{
    cout << "Subtraction" << endl;
    Complex c;
    c.real = this->real - a.real;
    c.img = this->img - a.img;
    return c;
}

Complex Complex::mul(Complex a)
{
    cout << "Multilpliaction" << endl;

    Complex c;
    c.real = this->real * a.real;
    c.img = this->img * a.img;
    return c;
}

Complex Complex::div(Complex a)
{
    cout << "Division" << endl;
    Complex c;
    c.real = this->real / a.real;
    c.img = this->img / a.real;
    return c;
}