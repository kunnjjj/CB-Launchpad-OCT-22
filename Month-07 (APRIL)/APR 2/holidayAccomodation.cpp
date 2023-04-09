#include <bits/stdc++.h>
using namespace std;

unordered_map<int,vector<pair<int,int>>> graph;
int N;
int dfs(int root,int par,long long &ans) // dfs, number of children root has in its subtree, including itself
{
    int myChildren=1; 
    for(pair<int,int> edge:graph[root])
    {
        int nbr=edge.first;
        if(nbr==par) continue;
        int wt=edge.second;
        int childrenInSubtreeOfNbr=dfs(nbr,root,ans);
        myChildren+=childrenInSubtreeOfNbr;
        ans+=min(childrenInSubtreeOfNbr,N-childrenInSubtreeOfNbr) * 2LL * wt;
    }
    return myChildren;
}

void solve()
{
    int n; cin>>n;
    N=n;

    for(int i=1;i<=n;i++)
    {
        graph[i].clear();
    }

    for(int i=0;i<n-1;i++)
    {
        int x,y,wt; cin>>x>>y>>wt;
        graph[x].push_back({y,wt});
        graph[y].push_back({x,wt});
    }

    long long ans=0;
    int src=2;// 1...N
    dfs(src,-1,ans);
    cout<<ans<<endl;



}

int main()
{
    int t; cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        solve();
        
    }

    return 0;
}