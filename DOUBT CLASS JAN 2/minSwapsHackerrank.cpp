#include<iostream>
using namespace std;

int find_cycle_len(int i,int *A,int *visited) // i denoted mai abhi kaunse index par hun
{
    // above function gives me len  from index=i onwards until cycle is found
    if(visited[i]==1) return 0;

    visited[i]=1;
    int new_pos=A[i];

    return 1 + find_cycle_len(new_pos,A,visited);
}

int main()
{
    int n; cin>>n;
    int A[n+1];

    for(int i=1;i<=n;i++) cin>>A[i];

    int visited[n+1]={0};
    // if visited[i]==0 this means that index=i, has not been visited yet
    // if visited[i]==1 this means that index=i, has been visited

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            int len=find_cycle_len(i,A,visited);
            // len= 5
            ans+=len-1;
        }
    }
    cout<<ans<<endl;

    return 0;
}