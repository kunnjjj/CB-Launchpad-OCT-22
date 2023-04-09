class Solution {
public:
    vector<vector<int>> dp;
    int maxAmount(int L,int R,vector<int> &A)
    {
        if(L>R)
        {
            // all balloon in L..R have been popped out, so no more amount
            return 0;
        }

        if(dp[L][R]!=-1)
        {
            return dp[L][R];
        }
        // maxAmount(L,R) what is max amount on popping all balloons from L...R
        // we try every possible balloon in L...R
        // and ith balloon is popped last in range[L..R], al other balloons being in tact
        int ans=0;
        for(int i=L;i<=R;i++)
        {
            
            int cost=(L-1>=0?A[L-1]:1) * A[i] * (R+1<(int)A.size()?A[R+1]:1) + maxAmount(L,i-1,A) + maxAmount(i+1,R,A);
            ans=max(ans,cost);
        }
        return dp[L][R]=ans;
    }

    int maxCoins(vector<int>& A) {
        int n=A.size();
        // dp=vector<vector<int>> (n,vector<int> (n,-1));
        // return maxAmount(0,n-1,A);
        // maxAmount(0,n-1);
        // return dp[0][n-1];
        vector<vector<int>> DP(n,vector<int> (n));

        for(int L=n-1;L>=0;L--) 
        {
            for(int R=L;R<n;R++)
            {
                int ans=0;
                for(int i=L;i<=R;i++)
                {
                    // int cost=(L-1>=0?A[L-1]:1) * A[i] * (R+1<(int)A.size()?A[R+1]:1) + maxAmount(L,i-1,A) + maxAmount(i+1,R,A);
                    // ans=max(ans,cost);
                    int cost=(L-1>=0?A[L-1]:1) * A[i] * (R+1<(int)A.size()?A[R+1]:1) + (L<=i-1?DP[L][i-1]:0) + (i+1<=R?DP[i+1][R]:0);
                    ans=max(ans,cost);
                }
                DP[L][R]=ans;
            }
        }
        return DP[0][n-1];
    }
};