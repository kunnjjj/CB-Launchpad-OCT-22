#include<iostream>
using namespace std;

int main()
{
    
    int a=10;
    int* ptr=&a;
    
    cout<<"original a: "<<a<<endl;
    (*ptr)++;
    cout<<"after (*ptr)++, a: "<<a<<endl;

    int &b=a; // reference variable is just a nickname 
    // for original variable a

    cout<<"a ka address: "<<&a<<endl;
    cout<<"b ka address: "<<&b<<endl; // 

    cout<<"declaring b as reference, b: "<<b<<endl;
    b++;
    cout<<"incrementing b, b: "<<b<<endl;

    cout<<"printing a, a: "<<a<<endl;
    int x;
    cout<<sizeof(x)<<endl;

    

    return 0;
}