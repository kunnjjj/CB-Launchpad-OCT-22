class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        
        multiset<int> ms;
        vector<int> ans;
        int n=A.size();
        for(int i=0;i<n;i++)
        {
            ms.insert(A[i]);
            if(i>=k)
            {
                auto it=ms.find(A[i-k]);
                ms.erase(it);
            }
            if(i>=k-1)
            {
                ans.push_back(*ms.rbegin());
            }
        }
        return ans;
    }
};