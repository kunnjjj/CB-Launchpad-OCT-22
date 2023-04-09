#include<iostream>
using namespace std;

int main()
{
    int a=10;
    cout<<(&a)<<endl; // '&' address of operator
    // & will tell us where has the memory be assigned to a

    int *ptr= &a; // int* ptr=&a; // both are same things

    cout<<"a contains value: "<<a<<endl;
    cout<<"&a is : "<<&a<<endl;
    cout<<"ptr contains value: "<<ptr<<endl;
    cout<<"&ptr is: "<<&ptr<<endl;
    cout<<"*ptr , value at: "<<(*ptr)<<endl;
    cout<<"*(&a): "<<(*(&a))<<endl;

    return 0;
}