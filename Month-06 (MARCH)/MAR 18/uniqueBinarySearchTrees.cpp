class Solution {
public:
    vector<int> dp;
    int count(int n)
    {
        // count(i):number of trees that can be formed using 'i' nodes
        if(n==0)
        {
            return 1;
        }
        if(dp[n]!=-1) return dp[n];

        int ans=0;
        for(int root=1;root<=n;root++)
        {
            ans+=count(root-1) * count(n-root);
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        // dp=vector<int> (n+1,-1);
        // return count(n);
        vector<int> dp2(n+1);
        dp2[0]=1;
        for(int i=1;i<=n;i++)
        {
            // dp2[i]: number of trees that can be formed using 'i' nodes
            for(int root=1;root<=i;root++)
            {
                dp2[i]+=dp2[root-1] * dp2[i-root];
            }
        }
        // i=3
        return dp2[n];
    }
};