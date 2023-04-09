// O(N*logK)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<(int)nums.size();i++)
        {
            if(1 + (int)pq.size() <=k)
            {
                pq.push(nums[i]);
            }
            else if(nums[i]> pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
    // QUICK SELECT: O(N)
};