#include<iostream>
#include<string>
using namespace std;



 class Person{
public:
    string name;
    int age;
    Person(){ }

 };


 class Student:public Person{
    public:
    int rollno;

void getInfo(){
    cout<<name<<endl;
    cout<<age<<endl;
    cout<<rollno<<endl;

}
 };

 int main()
 {
    Student s1;
    s1.name="bhushan";
    s1.age=12;
    s1.rollno=101;


    s1.getInfo();
    return 0;
 }