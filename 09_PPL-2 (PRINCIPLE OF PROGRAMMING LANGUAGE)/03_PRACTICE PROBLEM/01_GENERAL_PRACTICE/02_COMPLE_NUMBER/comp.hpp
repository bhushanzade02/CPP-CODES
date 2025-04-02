class Complex
{
public:
    double real;
    double img;

    Complex();
    void display();

    Complex add(Complex a );
    Complex sub(Complex a );
    Complex mul(Complex a);
    Complex div(Complex a);
};