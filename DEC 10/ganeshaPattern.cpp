#include<iostream>
using namespace std;
int main() {
	int n; cin>>n;
	//(n-1)/2
	// (n-1)/2 = 1 + (n-1/2 -1 )
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			cout<<"*";
		}
		else if(i>=(n/2)+1)
		{
			cout<<"*";
		}
		else
		{
			cout<<" ";
		}
	}
	cout<<endl;
	for(int i=1;i<=(n-1)/2 -1; i++) //1st line already considered
	{
		for(int j=1;j<=(n+1)/2;j++)
		{
			if(j==1 || j==(n+1)/2) cout<<"*";
			else cout<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++) cout<<"*";
	cout<<endl;
	// 1




	// (n-1)/2

	for(int i=1;i<=(n-1)/2-1 ;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j==(n+1)/2 || j==n) cout<<"*";
			else cout<<" ";
		}
		cout<<endl;
	}
	for(int j=1;j<=n;j++)
	{
		if(j<=(n+1)/2 || j==n) cout<<"*";
		else cout<<" ";
	}
	cout<<endl;
	return 0;
}
