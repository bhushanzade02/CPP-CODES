#include <iostream>
#include <vector>
#include <string>
#include "emp.hpp"

using namespace std;

void Employee::displayInfo()
{
    cout << "Employee Name" << empname << endl;
    cout << "Employee ID" << empid << endl;
    cout << "Employee Salary" << salary << endl;
    cout << "DepartMent Name" << deptname << endl;
}

vector<Employee>employees;

void Employee::addemp(string name, int id, string dept, double sal)
{
    employees.push_back(Employee(name, id, dept, sal));
    cout << "Employee Added Successfully!\n";
}

void Employee::displayemp()
{
    if (employees.empty())
    {
        cout << "NO EMPLOYEES AVAILABLE" << endl;
        return;
    }

    cout << "\n EMployees Records\n"
         << endl;
    for (auto &emp : employees)
    {
        emp.displayInfo();
    }
}

void Employee::searchemp(int id)
{
    for (auto &emp : employees)
    {
        if (emp.empid == id)
        {
            cout << "Employee Found" << endl;
            emp.displayInfo();
            return ;
                }
    }
    cout << "EMPLOYEE WITH ID" << id << "Is not found " << endl;
}

void Employee::deleteemp(int id)
{

    for (auto it = employees.begin(); it != employees.end(); ++it)
    {
        if (it->empid ==id)
        {
            employees.erase(it);
            cout << " Record Deleted Succesfully " << endl;
            return;
        }
    }
    cout << "EMPLOYEE WITH ID " << id << "NOt found.\n";
}
