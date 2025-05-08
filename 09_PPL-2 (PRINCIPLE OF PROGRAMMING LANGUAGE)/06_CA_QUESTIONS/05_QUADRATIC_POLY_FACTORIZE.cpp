#include <iostream>
#include <cmath>
using namespace std;

class Quadratic {
private:
    double a, b, c;

public:
    // Constructor to initialize the coefficients a, b, and c
    Quadratic(double a_, double b_, double c_) {
        a = a_;
        b = b_;
        c = c_;
    }

    // Method to factorize the quadratic equation
    void factorize() {
        // Discriminant of the quadratic equation
        double disc = b * b - 4 * a * c;

        // Case 1: Real and Distinct Roots
        if (disc > 0) {
            double root1 = (-b + sqrt(disc)) / (2 * a);
            double root2 = (-b - sqrt(disc)) / (2 * a);
            cout << "Real and Distinct Roots:" << endl;
            cout << "z1 = " << root1 << ", z2 = " << root2 << endl;
            cout << "Factorized Form: " << a << "(x - " << root1 << ")(x - " << root2 << ")" << endl;
        }
        // Case 2: Real and Equal Roots
        else if (disc == 0) {
            double root = -b / (2 * a);
            cout << "Real and Equal Roots:" << endl;
            cout << "z1 = z2 = " << root << endl;
            cout << "Factorized Form: " << a << "(x - " << root << ")^2" << endl;
        }
        // Case 3: Complex Roots
        else {
            double realPart = -b / (2 * a);
            double imagPart = sqrt(-disc) / (2 * a);
            cout << "Complex Roots:" << endl;
            cout << "z1 = " << realPart << " + " << imagPart << "i" << endl;
            cout << "z2 = " << realPart << " - " << imagPart << "i" << endl;
            cout << "Factorized Form: " << a << "(x - (" << realPart << " + " << imagPart << "i))(x - (" << realPart << " - " << imagPart << "i))" << endl;
        }
    }
};

int main() {
    double a, b, c;
    cout << "Enter coefficients a, b, and c for the quadratic equation ax^2 + bx + c:" << endl;
    cin >> a >> b >> c;

    // Check for quadratic equation condition
    if (a == 0) {
        cout << "Not a quadratic equation!" << endl;
        return 1;  // Not a quadratic equation
    }

    // Create an object of the Quadratic class and factorize
    Quadratic q(a, b, c);
    q.factorize();
    return 0;
}
