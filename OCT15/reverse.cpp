#include<iostream>
using namespace std;

int main()
{
    int n; 
    cin >> n;
    int rev=0;
    while (n>0)
    {
        int dig=n%10;  // last digit nikal rahe hai
        rev=rev*10 + dig;
        n=n/10;
    }

    cout<<"reverse is: ";
    cout<<rev;
    return 0;
}