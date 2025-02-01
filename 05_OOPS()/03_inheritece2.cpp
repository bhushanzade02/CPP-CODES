#include<iostream>
#include<string>
using namespace std;



 class Person{
public:
    string name;
    int age;


    // parametrized constructor 
    Person(string name, int age ){
        this->name=name;
        this->age=age;

     }

 };


 class Student:public Person{
    public:
    int rollno;



    Student(string name , int age , int rollno): Person(name, age)
    {
        this->rollno=rollno;
    }

void getInfo(){
    cout<<name<<endl;
    cout<<age<<endl;
    cout<<rollno<<endl;

}
 };

 int main()
 {
   Student s1("RAHUL",21,012);

    s1.getInfo();
    return 0;
 }