class Rectangle {
    private:
    double length;
    double width;

public:
 Rectangle(double l=1.0,double w=1.0); //constructor 
 void setDimensions(double l, double w);
 double getArea();
 double getPerimeter();
 void display();

};