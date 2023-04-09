// https://leetcode.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {

        deque<int> q;
        // queue<int> q;
        // stack<int> s;
        // list<int> l;
        vector<int> ans;
        int n=A.size();
        for(int i=0;i<n;i++)
        {
            while(!q.empty() && q.front()<=i-k) q.pop_front();

            while(!q.empty() && A[q.back()]<=A[i]) q.pop_back();

            q.push_back(i);
            if(i>=k-1) ans.push_back(A[q.front()]);

        }
        return ans;

    }
};