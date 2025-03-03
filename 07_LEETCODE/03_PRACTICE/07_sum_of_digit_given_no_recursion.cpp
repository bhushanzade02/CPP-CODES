
#include <iostream>
using namespace std;
int SumOfDigit(int n)
{
    if(n==0){
        return 0;
    }
    return (n%10)+SumOfDigit(n/10);

}


int main()
{
 int result =SumOfDigit(1234);
 cout<<result<<endl;
    return 0;
}