#include<iostream>
#include<string>
using namespace std;



class Teacher{
    public:
      string name;
      string dept;
      string subject;
      double salary ;




// // PAramterized Constructor 
// Teacher(string n, string d,string s, double sal){
//     this->name=n;
//     this->dept=d;
//     this->subject=s;
//     this->salary=sal;
  
// }


// copy constructor 
Teacher(Teacher &orgobj){
    this->name =orgobj.name;
    this->dept=orgobj.dept;
    this->subject=orgobj.subject;
    this->salary=orgobj.salary;
}



void getInfo(){
   cout<< name<< endl;
    cout<<dept<<endl;
    cout<<subject<<endl;
    cout<<salary<<endl;



}

};


int main(){

    Teacher t1("bhsuhan","cs","maths",12344);
   Teacher t2(t1);

t2.getInfo();
return 0;

};