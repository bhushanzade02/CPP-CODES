#include <iostream>
using namespace std;

int main() {
    double n;
    cout << "Enter a decimal number: ";
    cin >> n;

    int integerPart = (int)n;  // Get integer part
    double fractionalPart = n - integerPart;  // Get decimal part

    int denominator = 1;
    while (fractionalPart != (int)fractionalPart) { // Keep multiplying till fraction becomes an integer
        fractionalPart *= 10;
        denominator *= 10;
    }

    int numerator = (int)fractionalPart; // Now it's an integer

    // Display result
    cout << "Integer part: " << integerPart << endl;
    cout << "Fractional part: " << numerator << "/" << denominator << endl;
    cout << "Mixed fraction: " << integerPart << " + " << numerator << "/" << denominator << endl;

    return 0;
}
