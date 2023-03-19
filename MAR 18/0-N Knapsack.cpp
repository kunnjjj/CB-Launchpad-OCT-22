#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int func(vector<int> &wt,vector<int> &val,int i,int W)
{
	if(i==(int)wt.size())
	{
		return 0;
	}

	if(dp[i][W]!=-1)
	{
		return dp[i][W];
	}

	int op1=INT_MIN,op2=INT_MIN;
	// choose
	if(W >= wt[i])
	{
		op1=val[i] + func(wt,val,i+1,W-wt[i]);
	}
	
	//not choose
	op2=func(wt,val,i+1,W);
	return dp[i][W]=max(op1,op2);
	

	// if(num==0)
	// {
	// 	return 43;
	// }
	// else if(num!=0)
	// {
	// 	return 1002;
	// }

}

int main() {
	int N,W; cin>>N>>W;

	dp=vector<vector<int>> (N,vector<int> (W+1,-1));

	vector<int> wt(N);
	vector<int> val(N);

	for(int i=0;i<N;i++) cin>>wt[i];
	for(int i=0;i<N;i++) cin>>val[i];

	// cout<<func(wt,val,0,W);
	vector<vector<int>> dp2(N+1,vector<int> (W+1));

	for(int i=N-1;i>=0;i--)
	{
		for(int j=0;j<=W;j++)
		{
			// dp[i][j] ith item and j weight baaki hai
			int op1=INT_MIN,op2=INT_MIN;
			if(j-wt[i]>=0)
			{
				op1=val[i] + dp2[i+1][j-wt[i]];
			}
			op2=dp2[i+1][j];

			dp2[i][j]=max(op1,op2);
		}
	}	
	cout<<dp2[0][W];

	return 0;
}