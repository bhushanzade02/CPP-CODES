#include<iostream>
#include<string>
using namespace std;



 class Person{
public:
    string name;
    int age;



 };


 class Student:public Person{
    public:
    int rollno;


 };


 class gradStudent :public Student{
    string res;

 }

 int main()
 {
  gradStudent s1;
  s1.name="bhsuhan";
  s1.age=12;
  s1.res="phyics"
  
  cout<<age<<endl;
  cout<<rollno<<end;
  cout<<res<<endl;
    return 0;
 };