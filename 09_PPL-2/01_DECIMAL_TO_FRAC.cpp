#include <iostream>
using namespace std;

// Find biggest number that divides both
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    double n ; // Our number
cout<<"ENter a Number ";
cin>>n;
    int w = (int)n;  // Whole part
    double t = n - w;  // Tiny partd 

    cout << "fractional: " << t << endl;

    int d = 1000; // 3 decimal places (no pow function)
    int u = (t * d) + 0.5; // Manual rounding (no round function)

    int b = gcd(u, d); // Find biggest number
    
    u /= b; // Make small
    d /= b; // Make small

    cout << "farction : " << u << "/" << d << endl;

    return 0;
}
