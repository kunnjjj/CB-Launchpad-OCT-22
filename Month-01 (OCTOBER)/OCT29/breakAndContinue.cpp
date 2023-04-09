#include<iostream>
using namespace std;


int main()
{
    for(int i=0;i<10;i=i+1)
    {
        cout<<"Vipin"<<endl;
        if (i==5)
        {
            break;
        }
    }


    for(int i=0;i<10;i=i+1)
    {
        cout<<i<<endl;
    }

    cout<<endl;

    int i=0;
    for( ; ; )
    {
        if(i==10)
        {
            break;
        }
        cout<<i<<endl;
        i=i+1;
    }

    

    return 0;
}