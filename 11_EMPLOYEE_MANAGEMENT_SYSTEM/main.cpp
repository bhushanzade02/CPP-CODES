#include "emp.hpp"
#include <iostream>
using namespace std;

int main()
{
    int choice, id;
    string name, dept;
    double salary;
    Employee emp;

    while (true)
    {
        cout << "\nEMPLOYEE MANAGEMENT SYSTEM\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee by ID\n";
        cout << "4. Delete Employee by ID\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Department: ";
            getline(cin, dept);
            cout << "Enter Salary: ";
            cin >> salary;
            emp.addemp(name, id, dept, salary);
            break;

        case 2:
            emp.displayemp();
            break;

        case 3:
            cout << "Enter Employee ID to Search: ";
            cin >> id;
            emp.searchemp(id);
            break;

        case 4:
            cout << "Enter Employee ID to Delete: ";
            cin >> id;
            emp.deleteemp(id);
            break;

        case 5:
            cout << "Exiting Program. Goodbye!\n";
            return 0;

        default:
            cout << "Invalid Choice. Please Try Again.\n";
        }
    }
}
