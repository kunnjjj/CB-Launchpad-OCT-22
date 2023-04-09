#include<iostream>
#include<vector>
using namespace std;

long long maxN=1e6;
vector<long long> dp(maxN+1,-1);
long long M=1e9+7;
long long ways(long long n)
{
    if(n==0)
    {
        return 1;
    }

    if(dp[n]!=-1) return dp[n];

    long long ans=0;
    for(long long dice=1;dice<=min(n,(long long)6);dice++)
    {
        ans=(ans%M + ways(n-dice)%M)%M;
    }
    return dp[n]=ans;
}


long long mod_add(long long a,long long b,long long M)
{
    return (a%M + b%M)%M;
}
long long mod_sub(long long a,long long b,long long M)
{
    return ((a%M - b%M)%M + M)%M;
}

int main()
{
    long long n; cin>>n;
    // cout<<ways(n);

    vector<long long> WAYS(n+1);

    WAYS[0]=1;
    WAYS[1]=1;
    // for(long long i=2;i<=n;i++)
    // {
    //     long long ans=0;
    //     for(long long dice=1;dice<=min(n,6);dice++)
    //     {
    //         ans=(ans%M + ways(n-dice)%M)%M;
    //     }
    //     WAYS[i]=ans;
    // }
    // cout<<WAYS[n];
    long long k=6;
    for(long long i=2;i<=n;i++)
    {
        long long ans=mod_add(WAYS[i-1],WAYS[i-1],M);
        WAYS[i]=mod_sub(ans,(i-k-1>=0?WAYS[i-k-1]:0),M);
    }

    cout<<WAYS[n];
    return 0;
}