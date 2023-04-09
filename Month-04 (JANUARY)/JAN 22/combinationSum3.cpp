class Solution {
public:
    void func(int k,int n,vector<int> &cur,int dig,vector<vector<int>> &peti)
    {
        if(k==0 and n==0)
        {
            peti.push_back(cur);
            return ;

        }

        for(int cur_dig=dig;cur_dig<=min(n,9);cur_dig++)
        {
            cur.push_back(cur_dig);
            func(k-1,n-cur_dig,cur,cur_dig+1,peti);
            cur.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> peti;
        vector<int> cur;
        func(k,n,cur,1,peti);
        return peti;
    }
};