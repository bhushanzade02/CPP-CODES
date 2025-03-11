#include<iostream>
using namespace std;
void showInfo(int x)
{
    cout<<x<<endl;

}
void showInfo(string name)
{
    cout<<name<<endl;

}
void showInfo(double salary)
{
    cout<<salary<<endl;

}
int main()
{
    showInfo(10);
    showInfo("BHsuhan");
    showInfo(323.33);
}