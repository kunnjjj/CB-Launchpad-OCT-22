// https://leetcode.com/problems/house-robber/description/

class Solution {
public:
    int rob(vector<int>& loot) {
        int n=loot.size();
        vector<vector<int>> AMT(n+1,vector<int> (2));
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            // AMT[i][0]
            // max loot such that,
            // ith house ko nahi loota and we have considered
            // houses from i...n-1
            AMT[i][0]=max(AMT[i+1][0],AMT[i+1][1]);
            
            // AMT[i][1]
            // max loot such that,
            // ith house ko definitely loota and we have considered
            // houses from i...n-1
            AMT[i][1]=loot[i] + AMT[i+1][0];
            ans=max({ans,AMT[i][0],AMT[i][1]});
        }
        return ans;
    }
};

class Solution {
public:
    int rob(vector<int>& loot) {
        int n=loot.size();
        // vector<vector<int>> AMT(n+1,vector<int> (2));
        int ans=0;
        int Amt_iPlus1_0=0,Amt_iPlus1_1=0;
        for(int i=n-1;i>=0;i--)
        {
            // AMT[i][0]
            // max loot such that,
            // ith house ko nahi loota and we have considered
            // houses from i...n-1
            // AMT[i][0]=max(AMT[i+1][0],AMT[i+1][1]);
            int Amt_i_0=max(Amt_iPlus1_0,Amt_iPlus1_1);
            
            // AMT[i][1]
            // max loot such that,
            // ith house ko definitely loota and we have considered
            // houses from i...n-1


            // AMT[i][1]=loot[i] + AMT[i+1][0]; 
            int Amt_i_1=loot[i] + Amt_iPlus1_0;


            ans=max({ans,Amt_i_0,Amt_i_1}); 
            Amt_iPlus1_1=Amt_i_1;
            Amt_iPlus1_0=Amt_i_0;
        }
        return ans;
    }
};