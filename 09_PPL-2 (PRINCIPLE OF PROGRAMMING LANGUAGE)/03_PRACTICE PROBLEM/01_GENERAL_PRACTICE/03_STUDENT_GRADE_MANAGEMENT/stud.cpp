#include <iostream>
#include "stud.hpp"
#include <vector>

void Student::display()
{
    cout << "STUDENT NAME: " << name << endl;
    cout << "STUDENT ROLL NO: " << rollno << endl;
    cout << "STUDENT MARKS ";
    for (int mark : marks)
    {
        cout << mark << " ";
    }
}
double Student::Average(vector<int> a)
{
    int total = 0;
    for (int mark : a) // Use 'a' here, not 'marks'
    {
        total += mark;
    }

    cout << "\nTotal marks: " << total;
    
    // Ensure proper floating point division for the average
    double result = static_cast<double>(total) / a.size();
    cout << "\nAverage Marks: " << result;

    // Assuming this is for a specific fixed scale like 400 out of 500
    double temp = (static_cast<double>(400) / 500) * 100; // Fixed division
    cout << "\nPercentage: " << temp << "%" << endl;

    return result; // Return the result if needed
}

