#include<iostream>
using namespace std;


int main()
{
    int ans=0;
    int n; cin>>n;

    // for(int i=1;i<=n;i++)
    // {
    //     int x; cin>>x;
    //     ans^=x;
    // }
    // cout<<ans<<endl;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];
    
    for(int i=0;i<n;i++) ans^=A[i];
    cout<<ans<<endl;
    return 0;
}