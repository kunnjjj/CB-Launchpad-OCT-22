#include<bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, vector<int>> mp;
    int n; // 0...n-1

    graph(int x)
    {
        n = x;
    }

    void addEdge(int a, int b, bool directed = false) // undirected edges
    {
        mp[a].push_back(b);
        if (directed == false)
        {
            mp[b].push_back(a);
        }
    }
    void bfs(int src)
    {
        queue<int> q;
        // vector<bool> visited(n);
        unordered_map<int,bool> visited; //O(1) avg, worst: O(N)
        // map<int,bool> visited; O(logN)
        unordered_map<int,int> dist;
        int INF=(int)1e9;
        for(int i=0;i<n;i++) dist[i]=INF;
        q.push(src);
        visited[src]=true;
        dist[src]=0;


        while(!q.empty())
        {
            int frontNode=q.front();
            cout<<"node: "<<frontNode<<", dist: "<<dist[frontNode]<<endl;;
            q.pop();
            for(int nbr:mp[frontNode])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr]=true;
                    dist[nbr]=1+dist[frontNode];
                }
            }
        }
    }
};


int main()
{
    int n,m; cin>>n>>m;

    graph g(n);
    for(int i=0;i<m;i++)
    {
        int x,y; cin>>x>>y;
        g.addEdge(x,y,false);
    }

    g.bfs(1);




    return 0;
}