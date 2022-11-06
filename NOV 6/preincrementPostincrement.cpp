#include<iostream>
using namespace std;

int main()
{
    int x=5;
    int y=x++;

    cout<<"y: "<<y<<endl;


    x=5;
    y=x++ + ++x;
    cout<<"y: "<<y<<endl;
    cout<<"x: "<<x<<endl;

    x=5;
    int z=0;
    z=(--x) * (++x) + (--x) + (x++);

    cout<<"x: "<<x<<endl;
    cout<<"z: "<<z<<endl;
    
    return 0;
}