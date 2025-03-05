#include <iostream>

using namespace std;
struct emp
{
    string name;
    int eid;
    int age;
    double salary;
};

int main()
{

    struct emp e;
    e.name = "bhushan";
    e.eid = 123;
    e.age = 23;
    e.salary = 12000;
    cout << "Name OF Employee:" << e.name << endl;
    cout << "ID of Employee:" << e.eid << endl;
    cout << "AGE of Employee" << e.age << endl;
    cout << "Salary Of Employee:" << e.salary << endl;
    cout<<sizeof(emp)<<endl;
   
    return 0;
}