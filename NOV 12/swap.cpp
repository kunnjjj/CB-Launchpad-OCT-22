#include<iostream>
using namespace std;


void swap(int &a,int &b) //a=4, b=10
{
    int temp=a; // temp=4
    a=b; // a=10
    b=temp; // b=4
}

void withOutTemp(int &a,int &b) // try with XOR
{

    // a=3, b=5
    a=a+b; 
    // a=8, b=5
    b=a-b;
    // a=8, b=3
    a=a-b;
    // a=5, b=3
}




int main()
{


    int a,b; cin>>a>>b;

    cout<<"old a: "<<a<<endl;
    cout<<"old b: "<<b<<endl;
    
    swap(a,b);

    cout<<"new a: "<<a<<endl;
    cout<<"new b: "<<b<<endl;

    withOutTemp(a,b);

    cout<<"again new a: "<<a<<endl;
    cout<<"again new b: "<<b<<endl;

    return 0;
}