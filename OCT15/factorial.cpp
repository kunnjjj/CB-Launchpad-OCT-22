#include<iostream>
using namespace std;

int main()
{
    int n; 
    cin>>n;

    int fact=1;
    int i=1;
    while (i<=n)
    {
        fact=fact*i;
        i=i+1;
    }
    cout<<"factorial is: ";
    cout << fact;


    return 0;
}