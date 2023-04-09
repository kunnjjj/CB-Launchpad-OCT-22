// https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        int n=H.size();
        stack<int> s;
        int ans=0;

        for(int i=0;i<n;i++)
        {
            int cur_val=H[i];
            while(!s.empty() && H[s.top()]>cur_val)
            {
                int idx=s.top();
                s.pop();
                int right=i;
                int left=(!s.empty() ? s.top() : -1);
                int Width=right-left-1;
                int Height=H[idx];
                ans=max(ans,Width*Height);
            }
            s.push(i);
        }

        while(!s.empty())
        {
            int idx=s.top();
            s.pop();
            int right=n;
            int left=(!s.empty() ? s.top() : -1);
            int Width=right-left-1;
            int Height=H[idx];
            ans=max(ans,Width*Height);
        }
        return ans;

    }
};