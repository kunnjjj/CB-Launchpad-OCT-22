#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool can_cows_be_placed(vector<int>& stalls,int cows,int min_dist)
{
    // first cow should be placed at stalls[0]
    cows--;

    int next_reqd_cor=stalls[0] + min_dist;
    for(int i=1;i<(int)stalls.size();i++) // O(N)
    {
        if(stalls[i]>=next_reqd_cor)
        {
            cows--;
            if(cows==0)
            {
                return true;
            }
            next_reqd_cor=stalls[i] + min_dist;
        }
    }
    return false;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> stalls(n);
        for (int i = 0; i < n; i++)
            cin >> stalls[i];

        sort(stalls.begin(), stalls.begin() + n);
        // sort(stalls.begin(),stalls.end());
        int ans=0;
        // //O(NlogN + N*(MAX-MIN))
        // for (int min_dist = 1;min_dist<=(stalls[n-1]-stalls[0]); min_dist++)  
        // {
        //     // O((MAX_STALL- MIN_STALL))

        //     if(can_cows_be_placed(stalls,c,min_dist)) // O(N)
        //     {
        //         ans=min_dist;
        //     }
        //     else break;
        // }
        // cout<<ans<<endl;

        int s=1,e=(stalls[n-1]-stalls[0]);
        while(s<=e) // O(log(MAX-MIN))
        {
            int mid=(s+e)/2; // s + (e-s)/2
            if(can_cows_be_placed(stalls,c,mid)) //O(N)
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }   
        // O( N* log(MAX-MIN) + NlogN)= O(N*log(MAX_STALL-MIN_STALL))
        cout<<ans<<endl;
    }
    // N=10^5
    // MAX-MIN=10^9
    // log(MAX-MIN)=9 * log2(10) = 30
    // T * N* 30
    return 0;
}