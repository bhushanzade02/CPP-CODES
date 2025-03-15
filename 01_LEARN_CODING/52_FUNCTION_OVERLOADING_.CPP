#include <iostream>
using namespace std;

int num1=20, num2=10;
void func()
{
    int sum = num1 + num2;
    cout << "Addition :" << sum << endl;
};
void func(int num1, int num2)
{
    int sum = num1 - num2;
    cout << "Subtraction" << sum << endl;
};
int main()
{
    func();
    func(10,20);
};
