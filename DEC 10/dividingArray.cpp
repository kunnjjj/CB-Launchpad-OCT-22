#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin>>t;
	while(t--)
	{
		int n;
		cin >> n;
		int A[n];
		for(int i=0;i<n;i++) cin>>A[i];
		sort(A,A+n);

		long long min_sum=0;
		for(int i=0;i<n;i+=2)
		{
			min_sum+=A[i+1]-A[i];
		}
		cout<<min_sum<<" ";
		long long max_ans=0;
		int i=0,j=n-1;
		while(i<j) // what will happen if i write i<=j
		{
			max_ans+=A[j]-A[i];
			i++;
			j--;
		}
		// for(int i=0;i<n/2;i++)
		// {
		// 	max_ans+=(-A[i]);
		// }
		// for(int i=n/2;i<n;i++)
		// {
		// 	max_ans+=(A[i]);
		// }
		cout<<max_ans<<endl;
		cout<<endl;
	}


	return 0;
}
