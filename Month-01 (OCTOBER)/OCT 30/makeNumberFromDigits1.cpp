#include<iostream>
using namespace std;
int main()
{
    long long p=1;
    int n;
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        int dig;
        cin>>dig;
        sum+=dig * p;
        p*=10;
    }
    cout<<sum<<endl;
    
    return 0;
}