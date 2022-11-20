#include<iostream>
using namespace std;
void print_factors(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<endl;
        }
    }
}

void print_factors(int n)
{
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<endl;
            int other=n/i;
            if(other!=i)
            {
                cout<<other<<endl;
            }
        }
    }
}
int main()
{
    int q; cin>>q;

    for(int i=0;i<q;i++)
    {
        int n; cin>>n;
        print_factors(n);
    }

    return 0;
}