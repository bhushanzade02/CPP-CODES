// IMPLEMENTATION FILE 
#include "Rectangel.hpp"
#include<iostream>
using namespace std;

// constructor 
Rectangle::Rectangle(double l, double w){
    length=l;
    width =w;

}

void Rectangle::setDimensions(double l , double w){
    length =l;
    width=w;

}

double Rectangle::getArea(){
    return length * width;
}

double Rectangle::getPerimeter(){
    return 2*(length + width );
}

void Rectangle::display(){
    cout<<"lenght"<<length<<",width"<<width<<endl;
    cout<<"Area"<<getArea()<<",Perimeter"<<getPerimeter()<<endl;

}