// https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        int n=H.size();


        vector<int> left(n);
        vector<int> right(n);

        stack<int> s;

        for(int i=0;i<n;i++)
        {
            int cur_val=H[i];
            while(!s.empty() && H[s.top()]>cur_val)
            {
                int idx=s.top();
                right[idx]=i;
                s.pop();
            }
            s.push(i);
        }

        while(!s.empty())
        {
            right[s.top()]=n;
            s.pop();
        }

        for(int i=n-1;i>=0;i--)
        {
            int cur_val=H[i];
            while(!s.empty() && H[s.top()]>cur_val)
            {
                int idx=s.top();
                left[idx]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
            left[s.top()]=-1;
            s.pop();
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            int W=right[i]-left[i]-1;
            ans=max(ans,W * H[i]);
        }
        return ans;

    }
};