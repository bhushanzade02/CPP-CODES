#include "stud.hpp"
#include <iostream>
using namespace std;
int main()
{
    Student s1("bhushan", 101, {85, 72, 65, 40, 97});
    Student s2("sid",102, {95, 91, 95, 60, 97});

    s1.display();
    s1.Average(s1.marks);
    cout<<endl;
    
    s2.display();
    s2.Average(s2.marks);
}