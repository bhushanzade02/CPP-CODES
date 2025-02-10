#include <iostream>
#include "cmplxbz.hpp"

int main()
{
    // Create objects
    cmplxbz obj1, obj2, resultAdd, resultSub;
    
    // Initialize objects
    obj1.real = 3.0;
    obj1.img = 2.0;
    obj2.real = 1.5;
    obj2.img = 4.5;
    
    // Display the initial values
    std::cout << "Object 1: ";
    obj1.display();
    std::cout << "Object 2: ";
    obj2.display();
    
    // Add the two objects
    resultAdd = obj1.add(obj2);
    std::cout << "Addition Result: ";
    resultAdd.display();
    
    // Subtract the two objects
    resultSub = obj1.subtract(obj2);
    std::cout << "Subtraction Result: ";
    resultSub.display();
    
    return 0;
}
