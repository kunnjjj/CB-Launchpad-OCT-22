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

    void dfs(int node,int &k)
    {
        k++;
        visited[node]=true;
        for(int nbr:mp[node])
        {
            if(!visited[nbr])
            {
                dfs(nbr,k);
            }
        }
    }

    void helper(int A,int B)
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                int k=0;
                dfs(i,k);
                ans+=min(k*1LL*A,A+ (k-1)*1LL* B);
            }
        }
        cout<<ans<<endl;
    }

};

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        int A,B; cin>>A>>B;

        graph g(n);

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            g.addEdge(a, b);
        }
        g.helper(A,B);

    }
    
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