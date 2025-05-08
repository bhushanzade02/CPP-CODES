#include <iostream>
#include <iomanip>
using namespace std;

bool isLeap(int y) { return y % 4 == 0 && (y % 100 || y % 400 == 0); }

bool valid(int d, int m, int y) {
    int dm[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeap(y)) return d <= 29;
    return m >= 1 && m <= 12 && d >= 1 && d <= dm[m - 1];
}

bool isPalin(string s) {
    for (int i = 0; i < 4; ++i)
        if (s[i] != s[7 - i]) return false;
    return true;
}

int main() {
    for (int y = 2000; y <= 2100; ++y)
        for (int m = 1; m <= 12; ++m)
            for (int d = 1; d <= 31; ++d)
                if (valid(d, m, y)) {
                    char s[9];
                    sprintf(s, "%02d%02d%04d", d, m, y);
                    if (isPalin(s))
                        printf("%02d-%02d-%04d\n", d, m, y);
                }
}
