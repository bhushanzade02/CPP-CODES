#include <iostream>
#include "comp.hpp"

int main()
{
    Complex obj1, obj2;
    obj1.real = 30;
    obj1.img = 24;
    obj1.display();

    obj2.real = 2;
    obj2.img = 3;
    obj2.display();

    Complex result = obj1.add(obj2);
    result.display();
    Complex resultsub = obj1.sub(obj2);
    resultsub.display();

    Complex resultmul = obj1.mul(obj2);
    resultmul.display();

    Complex resultdiv = obj1.div(obj2);
    resultdiv.display();
}