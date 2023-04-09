// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& A) {
        vector<int> sorted_A=A;
        sort(sorted_A.begin(),sorted_A.end());
        int n=A.size();
        int i=0,j=n-1;
        while(i<n && sorted_A[i]==A[i]) i++;
        if(i==n) return 0;
        while(j>=0 && sorted_A[j]==A[j]) j--;
        return j-i+1;
    }
};