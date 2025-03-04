
#include <iostream>
using namespace std;
int main()
{

    int a = 10;
    int *p = &a;         //pointer
    cout << p << endl;
    cout << *p << endl;
    cout << &a;



    int **q=&p;          //pointer to pointer
    cout<<q<<endl;
    cout<<*q<<endl;
    cout<<**q<<endl;
    cout<<&q<<endl;







    return 0;
}