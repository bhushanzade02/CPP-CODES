#include <iostream>
#include <cmath>  // For fabs() and pow()

using namespace std;


double fun(double x) {
    return x * x * x - x - 2;  
}

int main() {
    double a = 1, b = 2, c, eps = 0.001;
    int count = 1;  

    // check  signs of f(a) and f(b) are different
    if (fun(a) * fun(b) >= 0) {
        cout << "The interval does not contain a root." << endl;
        return 1;  
    }

    // start the bisection method
    while (fabs(b - a) > eps) {  // Loop until less than eps
        c = (a + b) / 2;  // Midpoint 

        // If f(c) is exactly roots arre find
        if (fun(c) == 0) {
            cout << "Exact root found: " << c << endl;
            break;
        }

        // update the interval based on the sign of f(c)
        if (fun(a) * fun(c) < 0) {
            b = c;  // Root is between a and c
        } else {
            a = c;  // Root is between c and b
        }

        
        cout << "Iteration " << count << ": c = " << c << endl;
        count++;
    }

 
    cout << "Approximate root after " << count - 1 << " iterations: " << c << endl;
    return 0;
}
