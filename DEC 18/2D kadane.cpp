#include<bits/stdc++.h>
using namespace std;
int main() {
	
	int n,m; cin>>n>>m;
	int A[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>A[i][j];
		}
	}
	int prefix[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			prefix[i][j]=(j-1>=0?prefix[i][j-1]:0) + A[i][j];
		}
	}

	int ans=-1e9;
	for(int L=0;L<m;L++)
	{
		for(int R=L;R<m;R++)
		{
			int cur=0;
			for(int i=0;i<n;i++)
			{
				int cur_ele=prefix[i][R]-(L-1>=0?prefix[i][L-1]:0);
				cur=max(cur + cur_ele,cur_ele);
				ans=max(ans,cur);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}