#include<iostream>
using  namespace std;

void func()
{
    class A{
        private:
        int a , b;
        public:
        void show()
        {
            cout<<"enter element a AND b";
            cin>>a>>b;
            cout<<a<<b;
        }
    };


    A obj ;
    obj.show();
}

int main()
{
    func();
}