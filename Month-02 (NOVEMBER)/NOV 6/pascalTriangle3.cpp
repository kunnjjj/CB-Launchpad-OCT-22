#include<iostream>
using namespace std;


int factorial(int n)
{
    int fact=1;
    for(int i=1;i<=n;i=i+1)
    {
        fact*=i;
    }
    return fact;
}

int nCr(int n,int r)
{
    int fact_n=factorial(n);
    int fact_r=factorial(r);
    int fact_n_r=factorial(n-r);

    return (fact_n / (fact_r * fact_n_r));
}

int main()
{

    int n;
    cin >> n;

    // for(int row=0;row<=n-1;row=row+1)
    // {
    //     for(int col=0;col<=row;col=col+1)
    //     {
    //         cout<<nCr(row,col)<<"\t";
    //     }   
    //     cout<<endl;
    // }
    
    for(int row=0;row<=n-1;row=row+1)
    {
        cout<<1<<"\t";
        int p=1;
        for(int col=1;col<=row;col=col+1)
        {
            p=p * (row-col+1);
            p=p/col;
            cout<<p<<"\t";
        }
        cout<<endl;
    }
    return 0;
}