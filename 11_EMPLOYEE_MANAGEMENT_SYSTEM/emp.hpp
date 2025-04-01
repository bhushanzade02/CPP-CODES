#include <string>
#include <iostream>
using namespace std;

class Employee
{
private:
    string empname;
    int empid;
    string deptname;
    double salary;

public:
    Employee()
    {
        empname = "unknown";
        empid = 0;
        deptname = "Unknown";
        salary = 0.0;
    }

    Employee(string name, int id, string dept, double sal)
    {
        empname = name;
        empid = id;
        deptname = dept;
        salary = sal;
    }



    void displayInfo();
    void addemp(string name, int id, string dept, double sal);
    void displayemp();
    void searchemp(int id);
    void deleteemp(int id);

    
};