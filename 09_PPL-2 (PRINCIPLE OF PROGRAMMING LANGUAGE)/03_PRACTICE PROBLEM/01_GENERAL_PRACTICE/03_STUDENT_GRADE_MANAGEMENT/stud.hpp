#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Student
{
    public:
    string name;
    int rollno;
    vector<int> marks;


    Student()
    {
        name = "unknown";
        rollno = 0;
        marks = {};
    }

    Student(string nam, int roll, vector<int> mark)
    {
        name = nam;
        rollno = roll;
        marks = mark;
    }

    void display();
    double Average(vector<int>marks);

   
};