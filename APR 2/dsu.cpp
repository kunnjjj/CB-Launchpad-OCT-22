#include<bits/stdc++.h>
using namespace std;

//merge communities HACKERRANK
class dsu
{
    public:
    vector<int> parent;
    vector<int> sz;
    int N;
    int CC;
    dsu(int n)
    {
        N=n;
        CC=n;
        parent=vector<int> (N+1);
        sz=vector<int> (N+1);
        for(int i=1;i<=n;i++) 
        {
            parent[i]=i;
            sz[i]=1;
        }
    }

    int find_par(int i) 
    {
        if(parent[i]==i) return i;
        return parent[i]=find_par(parent[i]);
    }
    
    void add_edge(int a,int b)
    {
        int par_a=find_par(a); // gives me parent at topmost level of the chain
        int par_b=find_par(b);
        if(par_a!=par_b)
        {   
            // if(sz[par_a] < sz[par_b])
            // {
            //     parent[par_a]=par_b;
            //     sz[par_b]+=sz[par_a];
            // }
            // else
            // {
            //     parent[par_b]=par_a;
            //     sz[par_a]+=sz[par_b];
            // }

            // ASSUMPTION PAR_A is that parent whos has less size
            if(sz[par_a] > sz[par_b]) swap(par_a,par_b);
            parent[par_a]=par_b;
            sz[par_b]+=sz[par_a];
            CC--;
        }   
    }

    int totalComponents()
    {
        return CC;
    }

    int sizeOfComponent(int x)
    {
        int par_x=find_par(x);
        return sz[par_x];
    }

    bool inSameComponent(int x,int y)
    {
        int par_x=find_par(x);
        int par_y=find_par(y);
        return par_x==par_y;
    }

};

int main()
{
    int n; cin>>n;
    int q; cin>>q;
    dsu d(n);

    for(int i=0;i<q;i++)
    {
        char x;
        cin>>x;
        if(x=='M')
        {
            int a,b; cin>>a>>b;
            d.add_edge(a,b);
        }
        else
        {
            int a; cin>>a;
            cout<<d.sizeOfComponent(a)<<endl;
        }
    }
    
    return 0;
}