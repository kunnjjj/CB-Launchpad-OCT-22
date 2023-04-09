// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
class Solution
{
	public:
	static bool comp(vector<int> &a,vector<int> &b)
	{
	    return a[2] < b[2];
	}
	
    vector<int> par;
    
    int get(int x)
    {
        if (x == par[x])
            return x;
        return par[x] = get(par[x]);
    }
    
    bool merge(int a,int b)
    {
        int par_a=get(a),par_b=get(b);
        if(par_a==par_b) // cycle will get formed on adding this edge
        return false;
        
        par[par_a]=b;
        return true;
        
    }
    
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // int name[]
        // code here
        
        vector<int> visited(V);
        // visited[i] is marked true only edges of it have been pushed
        
        int anyNode=0; // V-1
        priority_queue<pair<int,int>> PQ; // -wts min priority queue
        
        // {-wt,node}
        for(vector<int> edge:adj[anyNode])
        {
            int wt=edge[1],nbr=edge[0];
            PQ.push({-wt,nbr});
        }
        int ans=0;
        visited[anyNode]=true;
        while(!PQ.empty())
        {
            pair<int,int> bestEdge=PQ.top();
            int node=bestEdge.second,wt=-bestEdge.first;
            PQ.pop();
            
            if(visited[node]) continue;
            ans+=wt;
            visited[node]=true;
            for(vector<int> edge:adj[node])
            {
                int wt=edge[1],nbr=edge[0];
                if(!visited[nbr])
                PQ.push({-wt,nbr});
            }
        }
        return ans;
        
    }
};