#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(100,vector<int> (100,-1));
int mod_diff(int a,int b,int M)
{
	return ((a%M - b%M)%M + M)%M;
}

int sum(int s,int e,vector<int> &prefix)
{
	return mod_diff(prefix[e],(s-1>=0?prefix[s-1]:0),100);
}

int totalSmoke(vector<int> &A,int L,int R,vector<int> &prefix)
{
	// totalSmoke(L,R) what is min amt of smoke generated when
	// all colors from A[L]....A[R] are mixed 
	
	if(L==R)
	{
		return 0;
	}

	if(dp[L][R]!=-1)
	{
		return dp[L][R];
	}

	int ans=INT_MAX; // (int)1e9
	for(int k=L;k<=R-1;k++) // we will every possible partition L...R-1 
	{
		ans=min(ans, sum(L,k,prefix)*sum(k+1,R,prefix) + totalSmoke(A,L,k,prefix) + totalSmoke(A,k+1,R,prefix));
	}
	return dp[L][R]=ans;
}

int main()
{
	int n; cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++) cin>>A[i];
	vector<int> prefix(n);
	for(int i=0;i<n;i++)
	{
		prefix[i]=((i-1>=0?prefix[i-1]:0) + A[i])%100;
	}



	// cout<<totalSmoke(A,0,n-1,prefix);
	vector<vector<int>> DP(n,vector<int> (n,INT_MAX));


	for(int L=n-1;L>=0;L--)
	{
		for(int R=L;R<=n-1;R++)
		{
			if(L==R)
			{
				DP[L][R]=0;
				continue;
			}
			int ans=INT_MAX;
			for(int k=L;k<=R-1;k++)
			{
				ans=min(ans,sum(L,k,prefix)*sum(k+1,R,prefix) + DP[L][k] + DP[k+1][R]);
			}
			DP[L][R]=ans;
		}
	}

	cout<<DP[0][n-1];
	return 0;
}