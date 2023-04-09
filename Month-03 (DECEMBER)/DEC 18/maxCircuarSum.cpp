#include<iostream>
#include<climits>
using namespace std;
int maxSum3(int *A,int n)
{
    // int best[n];
    // best[0]=A[0];
    // for(int i=1;i<n;i++)
    // {
    //     best[i]=max(best[i-1] + A[i], // continuing in prev best array
    //                 A[i]); // starting a new subarray
    // }
    int ans=A[0];
    int cur_sum=A[0];
    for(int i=1;i<n;i++)
    {
        cur_sum=max(cur_sum + A[i],
                    A[i]);
        ans=max(ans,cur_sum);
    }
    // for(int i=0;i<n;i++) ans=max(ans,best[i]);
    return ans;

}
int main() {
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		int A[n];
		for(int i=0;i<n;i++) cin>>A[i];

		int ans=maxSum3(A,n);

		int worst[n];
		worst[0]=A[0];
		for(int i=0;i<n;i++)
		{
			worst[i]=min(worst[i-1] + A[i],A[i]);
		}
		int sum=0,minEle=INT_MAX;
		for(int i=0;i<n;i++)
		{
			sum+=A[i];
			minEle=min(minEle,worst[i]);
		}
		ans=max(ans,sum-minEle);
		cout<<ans<<endl;
	}
	return 0;
}