#include<iostream>
using namespace std;



int main()
{
    int n; cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];

    int mx=0;
    for(int i=0;i<n;i++)
    {
        if(A[i] > mx)
        {
            mx=A[i];
        }
    }

    int freq[mx+1]={0};
    for(int i=0;i<n;i++)
    {
        int cur_ele=A[i];
        freq[cur_ele]++;
    }

    int idx=0;
    // idx denotes ki ab kaunse index ki value ko assign karna hai

    for(int i=0;i<=mx;i++) //i=5 
    {
        for(int j=1;j<=freq[i];j++) // freq[i]=3
        {
            A[idx]=i;
            idx++;
        }
    }

    for(int i=0;i<n;i++) cout<<A[i]<<" ";

    return 0;
}