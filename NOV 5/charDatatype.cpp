#include<iostream>
using namespace std;

int main()
{
    char x;
    cout<<sizeof(x)<<endl;


    for(char ch='A';ch<='E';ch=ch+1)
    {
        for(char ch2='A';ch2<=ch;ch2=ch2+1)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }


    return 0;
}