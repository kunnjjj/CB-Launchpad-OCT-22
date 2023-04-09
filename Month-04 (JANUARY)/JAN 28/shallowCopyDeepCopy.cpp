#include<iostream>
using namespace std;

class A
{   
    int *ptr;
    int B;
    public:
    A()
    {   
        B=10;
        ptr=&B;
    }
    A(A& obj) // A obj2=obj1;
    {
        B=obj.B;
        ptr=&B;
    }

    ~A()
    {
        cout<<"destructor called"<<endl;
    }

    void print()
    {
        cout<<"*ptr: "<<(*ptr)<<endl;
        cout<<"B: "<<B<<endl;
        cout<<"ptr: "<<ptr<<endl;
        cout<<endl;
    }

    void change()
    {
        (*ptr)=25;
    }
};

int main()
{
    A obj; 
    A obj2;

    obj.print();
    obj2.print();

    obj2=obj;

    obj2.change();
    obj.print();
    obj2.print();
    return 0;
}