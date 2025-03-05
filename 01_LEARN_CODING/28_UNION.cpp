
#include <iostream>
using namespace std;
union emp{
    int eid;
long salary;

};
int main()
{

    union emp e;
    e.eid=223;
    cout<<e.eid<<endl;
    e.salary=334334;

   cout<<e.salary<<endl;
 
    return 0;
}