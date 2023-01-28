#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node()
    {
        data=5;
    }
    node(int data)
    {
        this->data=data;
    }

    ~node()
    {
        cout<<"destructor called"<<endl;
    }
    void printVal()
    {
        cout<<"data is: "<<data<<endl;
    }
};

int main()
{
    //int *A=new int;
    // datatype *Name=new datatype;

    node *ptr=new node(10);

    int b=10;
    int *a=&b;

    cout<<(*a)<<endl;

    cout<<(*ptr).data<<endl;
    cout<<ptr->data<<endl;


    (*ptr).printVal();

    ptr->printVal();


    delete(ptr); // this time destructor will be called

    return 0;
}