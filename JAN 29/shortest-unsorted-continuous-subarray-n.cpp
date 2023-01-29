// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& A) {
        int left_sahi=-1;
        int i=0;
        int n=A.size();
        while(i<n)
        {
            if(left_sahi+1==i && (left_sahi==-1 or A[left_sahi]<=A[i]))
            {
                left_sahi++;
                i++;
            }
            else
            {
                while(left_sahi>=0 && A[left_sahi]>A[i]) left_sahi--;
                i++;
            }
        }
        if(left_sahi==n-1)
        {
            return 0;
        }
        int right_sahi=n;
        int j=n-1;
        while(j>=0)
        {
            if(j+1==right_sahi && (right_sahi==n or A[right_sahi]>=A[j]))
            {
               j--;
               right_sahi--; 
            }
            else
            {
                while(right_sahi<n && A[right_sahi] < A[j]) right_sahi++;
                j--;
            }
        }
        // cout<<"right_sahi: "<<right_sahi<<endl;
        // cout<<"left_sahi: "<<left_sahi<<endl;
        return right_sahi-left_sahi-1;
    }
};