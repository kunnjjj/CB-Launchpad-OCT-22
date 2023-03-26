#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class graph
{
public:
    unordered_map<int, vector<int>> mp;
    int n; // 0...n-1
    vector<bool> visited;

    graph(int x)
    {
        n = x;
        visited = vector<bool>(n);
    }

    void addEdge(int a, int b, bool directed = false) // undirected edges
    {
        mp[a].push_back(b);
        if (directed == false)
        {
            mp[b].push_back(a);
        }
    }

    void dfs(int node, int &cnt)
    {
        visited[node] = true;
        cnt++;
        // cout<<node<<" ";
        for (int nbr : mp[node])
        {
            if (visited[nbr] == false)
            {
                dfs(nbr, cnt);
            }
        }
    }

    // int numberOfConnectedComp()
    // {
    //     int cc=0;
    //     // for(int i=0;i<n;i++)
    //     for(int i=0;i<=n-1;i++)
    //     {
    //         if(visited[i]==false)
    //         {
    //             dfs(i);
    //             cc++;
    //             cout<<endl;
    //         }
    //     }

    //     return cc;
    // }

    vector<int> getComponents()
    {
        vector<int> components;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                int cnt = 0;
                dfs(i, cnt);
                components.push_back(cnt);
            }
        }
        return components;
    }
    long long get_ans(int n)
    {
        long long ans = (1LL*n * (n - 1))/ 2;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                int cnt = 0;
                dfs(i, cnt);
                ans-=(1LL*cnt*(cnt-1))/2;
            }
        }
        return ans;
    }

};

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    graph g(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    cout<<g.get_ans(n)<<endl;
    // cout<<"number of cc: "<<endl;
    // vector<int> components = g.getComponents();
    // int N = components.size();
    // vector<int> suffixSum(N + 1);

    // for (int i = N - 1; i >= 0; i--)
    // {
    //     suffixSum[i] = components[i] + suffixSum[i + 1];
    // }

    // long long ans = 0;

    // for (int i = 0; i < N; i++)
    // {
    //     // ans+=components[i] * sum(i+1...N-1)
    //     ans += components[i] * 1LL * suffixSum[i + 1];
    // }
    // cout << ans << endl;

    return 0;
}