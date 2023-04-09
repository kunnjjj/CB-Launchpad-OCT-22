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

    int _bfs01(int src, int dest)
    {
        deque<int> q;
        // vector<bool> visited(n);
        unordered_map<int, bool> visited; // O(1) avg, worst: O(N)
        // map<int,bool> visited; O(logN)
        unordered_map<int, int> dist;
        int INF = (int)1e9;
        for (int i = 1; i <= n; i++)
            dist[i] = INF;

        q.push_back(src);
        visited[src] = true;
        dist[src] = 0;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop_front();

            for (pair<int, int> EDGE : mp[frontNode])
            {
                int edgeWt = EDGE.second;
                int nbr = EDGE.first;
                if (!visited[nbr])
                {
                    if (edgeWt == 0)
                    {
                        q.push_front(nbr);
                        // visited[nbr]=true;
                        // dist[nbr]=dist[frontNode];
                    }
                    else
                    {
                        q.push_back(nbr);
                        // visited[nbr]=true;
                        // dist[nbr]=distance[frontNode]+1;
                    }
                    visited[nbr] = true;
                    dist[nbr] = edgeWt + dist[frontNode];
                }
            }
        }

        return dist[dest];
    }
    void clear_list(int key)
    {
        mp[key].clear();
    }
};

void solve_test_case()
{
    int n;
    int l, s;
    cin >> n >> l >> s;
    vector<pair<int, int>> ladders(l);
    vector<pair<int, int>> snakes(s);
    for (int i = 0; i < l; i++)
    {
        cin >> ladders[i].first >> ladders[i].second;
    }

    for (int i = 0; i < s; i++)
        cin >> snakes[i].first >> snakes[i].second;

    graph g(n);
    for (int i = 1; i <= n; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            if (i + dice <= n)
            {
                g.addEdge(i, i + dice, 1, true);
            }
        }
    }
    // CLEAR EDGES
    for (pair<int, int> ladder : ladders)
    {
        g.clear_list(ladder.first);
    }
    for (pair<int, int> snake : snakes)
    {
        g.clear_list(snake.first);
    }

    for (pair<int, int> ladder : ladders)
    {
        g.addEdge(ladder.first, ladder.second, 0, true);
    }

    for (pair<int, int> snake : snakes)
    {
        g.addEdge(snake.first, snake.second, 0, true);
    }
    // g.print_graph();
    cout << g._bfs01(1, n) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve_test_case();
    }

    return 0;
}