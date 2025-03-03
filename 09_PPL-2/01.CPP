
#include <iostream>
#include <cmath>
using namespace std;


int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}



int 

int main()
{

    double n = 12.345;

    int intgerPart = (int)n; 
    double rem = n - intgerPart;



    cout << rem << endl;
    cout << intgerPart;

    return 0;
}