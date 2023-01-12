// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:

    bool contains_distinct(int *freq,int k)
    {
        for(int i=0;i<=255;i++)
        {
            if(freq[i]>=k+1) return false;
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0;
        int i=0;
        int freq[256]={0};
        int k=1;
        // O(N * A) A=256
        // HOMEWORK: O(N+A)
        for(int j=0;j<n;j++) 
        {
            freq[s[j]]++;
            while(contains_distinct(freq,k)==false)
            {
                freq[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            // now string s[i.....j] is being considered
        }

        // for(int L=0;L<n;L++)
        // {
        //     for(int R=L;R<n;R++)
        //     {
        //         string temp=s.substr(L,R-L+1);
        //         cout<<temp<<endl;

        //         int freq[256]={0};
        //         for(int i=0;i<(int)temp.size();i++)
        //         {
        //             freq[temp[i]]++;
        //         }

        //         if(contains_distinct(freq))
        //         {
        //             ans=max(ans,R-L+1);
        //         }
        //     }
        // }
        return ans;
    }
};