// this was given as a homework hence wont be available in notes
class Solution {
public:
    int quickSelect(int s,int e,int k,vector<int> &A)
    {
        if(s>e) return -1; // 
        if(s==e) return A[s]; 
        int pivot=A[s];
        int idx=e;
        
        for(int i=e;i>=s+1;i--)
        {
            if(A[i]>=pivot)
            {
                swap(A[idx],A[i]);
                idx--;
            }
        }
       
        // idx
        // s=3,e=7
        // k=5 idx=4
        swap(A[idx],A[s]);
        // cout<<"s: "<<s<<" ,e: "<<e<<endl;
        // cout<<"idx: "<<idx<<endl;
        // for(int x:A) cout<<x<<" ";
        // cout<<endl;

        int right=(e-idx);
        if(right+1==k) return A[idx];
        
        if(k<=right)
        {
           return quickSelect(idx+1,e,k,A); 
        }
        else
        {
            return quickSelect(s,idx-1,k-(right+1),A);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
       return quickSelect(0,(int)nums.size()-1,k,nums);
    }
    // QUICK SELECT: O(N)
};