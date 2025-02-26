#include "cmplxbz.hpp"

// Constructor
cmplxbz::cmplxbz()
{
    real = 0;
    img = 0;
    std::cout << "In cmplxbz default constructor ";
}

// Display function
void cmplxbz::display()
{
    std :: cout << this->real ;
 
    if(this->img>0)
    {
        std::cout << " + "; 
    }else   std::cout << "";
    std :: cout << this->img << "i" << std::endl;
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
