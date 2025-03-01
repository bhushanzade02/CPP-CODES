#include "Rectangel.hpp"
#include<iostream>
using namespace std;


int main()
{
    Rectangle react(5,3);
    react.display();
    react.setDimensions(7,4);
    cout<<"\n After Modifying Dimensions ";
    react.display();

    return 0;
}