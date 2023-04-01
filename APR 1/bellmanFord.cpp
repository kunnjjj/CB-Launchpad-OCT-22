#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, vector<pair<int, int>>> mp;
    int n; // 1...n

    vector<vector<int>> edges; // a=egdes[i][0], b=edges[i][1], wt=edges[i][2]
    graph(int x)
    {
        n = x;
    }

    void addEdge(int a, int b, int wt, bool directed = false) // undirected edges
    {
        vector<int> v(3);
        v[0] = a, v[1] = b, v[2] = wt;
        edges.push_back(v);
        // mp[a].push_back(b);
        // mp[a].push_back({b, wt});
        // if (directed == false)
        // {
        //     mp[b].push_back({a, wt});
        // }
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

    void bellmanFord(int src, bool directed = false)
    {

        int INF = (int)1e9;
        unordered_map<int, int> dist;
        for (int i = 1; i <= n; i++)
            dist[i] = INF;

        dist[src] = 0;
        int V = n, E = (int)edges.size();
        for (int iter = 0; iter < V - 1; iter++)
        {
            for (int i = 0; i < E; i++)
            {
                int a = edges[i][0], b = edges[i][1], wt = edges[i][2];
                if (dist[a] + wt < dist[b])
                {
                    dist[b] = dist[a] + wt;
                }

                if (directed == false)
                {
                    if (dist[b] + wt < dist[a])
                    {
                        dist[a] = dist[b] + wt;
                    }
                }
            }
        }

        for (int i = 0; i < E; i++)
        {
            int a = edges[i][0], b = edges[i][1], wt = edges[i][2];
            if (dist[a] + wt < dist[b])
            {
                cout << "neg wt cycle exists" << endl;
                return;
            }

            if (directed == false)
            {
                if (dist[b] + wt < dist[a])
                {

                    cout << "neg wt cycle exists" << endl;
                    return;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (i == src)
                continue;
            if (dist[i] == INF)
                cout << -1 << " ";
            else
                cout << dist[i] << " ";
        }
    }
};

void solve()
{

    int n, m;
    cin >> n >> m;
    graph g(n);

    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        g.addEdge(x, y, wt, false);
    }
    int src;
    cin >> src;
    g.bellmanFord(src);
}

int main()
{
    solve();

    return 0;
}