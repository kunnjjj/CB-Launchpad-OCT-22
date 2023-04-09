#include<iostream>
using namespace std;

bool is_prime(int n)
{
    if(n<=1) return false;
    if(n==2) return true;

    if(n%2==0) return false;

    // for(int i=3;i<=n-1;i=i+2)
    // {
    //     if(n%i==0) return false;
    // }
    // return true;

    for(int i=3;i*i<=n;i=i+2)
    {
        if(n%i==0) return false;
    }

    return true;
}

int main()
{

    bool res=is_prime(998244352);
    if(res)
    {
        cout<<"prime"<<endl;
    }
    else
    {
        cout<<"not prime"<<endl;
    }
    return 0;
}

// cout<<"\t";