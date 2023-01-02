#include<iostream>
#include<algorithm>
using namespace std;
// https://www.hackerrank.com/challenges/minimum-swaps-2/problem
// int binarySeach(int *B,int target)
// {
//     int s=1,e=n;
//     while(s<=e)
//     {
//         int mid=(s+e)/2;
//         if(B[mid]==target) return mid;
//         else if(B[mid] )
//     }
// }
int cycleLen(int i,int *A,int *visited,int *B,int n)
{
    if(visited[i]==1) // i have previously visited this element
    {
        // len of chain now onwards is hence 0
        return 0;
    }
    // index=i se start hone wali chain ki length laakar do

    // int agleIndexParJanaHai=A[i];
    // int agleIndexParJanaHai=index[A[i]]; // we will get correct position of A[i]
    int agleIndexParJanaHai=-1;
    int s=1,e=n;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(B[mid]==A[i])
        {
            agleIndexParJanaHai=mid;
            break;
        }
        else if(B[mid] < A[i])
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    visited[i]=1;
    return 1 + cycleLen(agleIndexParJanaHai,A,visited,B,n);
}
int main()
{
    int n; cin>>n;
    int A[n+1];
    int B[n+1];
    int mx_size=0;

    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
        B[i]=A[i];
        
    }

    sort(B+1,B+1+n);

    // mx_size=B[n];
    // int index[mx_size+1];

    // for(int i=1;i<=n;i++)
    // {
    //     index[B[i]]=i;
    //     // this means that index of element B[i] is i
    // }

    int visited[n+1]={0};

    // visited[i]==0 -> abhi ye A[i] place nahi hua hai
    // visited[i]==1 -> idx=i, par element i.e. A[i] it is placed
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0) // agar is element ko pehle visit nahi kara tha
        {
            int len=cycleLen(i,A,visited,B,n);
            ans+=len-1;
        }
    }
    cout<<ans<<endl;

}
