#include<iostream>
using namespace std;


int main()
{
    int n; cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];

    int q; cin>>q;
    int max_left[n];

    int prefix[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        prefix[i]=sum;
    }


    int mx=A[0];
    for(int i=0;i<n;i++)
    {
        if(A[i] > mx) 
        {
            mx=A[i];
        }
        max_left[i]=mx;
    }


    for(int i=0;i<q;i++)
    {
        // kaam karte haiii
        int idx; cin>>idx;
        // cout<<max(A[0],A[1],A[2],.....,A[idx])<<endl;
        // int ans=A[0];
        // for(int j=0;j<=idx;j++)
        // {
        //     if(A[j] > ans)
        //     {
        //         ans=A[j];
        //     }
        // }
        int ans=max_left[idx];
        int sum=prefix[idx];
        cout<<"max in 0....idx: "<<ans<<endl;
        cout<<"sum in 0....idx: "<<sum<<endl;
    }

    return 0;
}