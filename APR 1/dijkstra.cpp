#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, vector<pair<int, int>>> mp;
    int n; // 1...n

    graph(int x)
    {
        n = x;
    }

    void addEdge(int a, int b, int wt, bool directed = false) // undirected edges
    {
        // mp[a].push_back(b);
        mp[a].push_back({b, wt});
        if (directed == false)
        {
            mp[b].push_back({a, wt});
        }
    }

    void print_graph()
    {
        for (auto p : mp)
        {
            cout << p.first << ": ";
            for (pair<int, int> edge : p.second)
            {
                cout << "{";
                cout << edge.first << ", ";
                cout << edge.second;
                cout << "} ";
            }

            cout << endl;
        }
    }

    void dijkstra(int src)
    {
        int INF=(int)1e9;
        unordered_map<int,int> dist;
        for(int i=1;i<=n;i++) dist[i]=INF;    

        set<pair<int,int>> s;
        // {wtFromSrc,Node}
        dist[src]=0;
        s.insert({dist[src],src});
        while(!s.empty())
        {
            pair<int,int> bestNode=*s.begin();
            s.erase(s.begin());
            int node=bestNode.second;
            int wtTillBestNode=bestNode.first;
            cout<<"node: "<<node<<" , "<<"wtTillBestNode: "<<wtTillBestNode<<endl;
            for(pair<int,int> edge:mp[node])
            {
                int nbr=edge.first;
                int edgeWt=edge.second;
                if(edgeWt + dist[node] < dist[nbr]) // nbr ke wt ko relax karo
                {
                    // either old instance exists in set
                    auto it=s.find({dist[nbr],nbr});
                    if(it!=s.end())
                    {
                        s.erase(it);
                    }
                    dist[nbr]=edgeWt + dist[node] ;
                    s.insert({dist[nbr],nbr});
                }
            }
        }

    }
};

void solve()
{

    int n,m; cin>>n>>m;
    graph g(n);

    for(int i=0;i<m;i++)
    {
        int x,y,wt; cin>>x>>y>>wt;
        g.addEdge(x,y,wt,false);
    }
    int src; cin>>src;
    g.dijkstra(src);
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
    

    return 0;
}