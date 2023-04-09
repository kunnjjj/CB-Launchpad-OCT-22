class Solution {
public:
    vector<vector<int>> dp;
    int lcs(string &s1,string &s2,int i,int j)
    {
        if(i==(int)s1.size() or j==(int)s2.size())
        {
            return 0;
        }

        if(dp[i][j]!=-1) // state already visited
        {
            return dp[i][j];
        }

        if(s1[i]==s2[j])
        {
            return dp[i][j]=1 + lcs(s1,s2,i+1,j+1);
            // dp[i][j]=1 + dp[i+1][j+1];
        }
        else
        {
            return dp[i][j]=max(lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1));
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        // dp=vector<vector<int>> (m,vector<int> (n,-1));
        // return lcs(s1,s2,0,0);

        vector<vector<int>> dp2(m+1,vector<int> (n+1));


        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                // dp2[i][j]= len of max common subsequence in s1[i...m-1] & s2[j...n-1]
                if(s1[i]==s2[j])
                {
                    dp2[i][j]=1 + dp2[i+1][j+1];
                }
                else
                {
                    dp2[i][j]=max(dp2[i+1][j],dp2[i][j+1]);
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<dp2[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp2[0][0];
    }
};