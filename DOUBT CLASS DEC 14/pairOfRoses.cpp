#include<iostream>
#include<algorithm>
using namespace std;
void solve()
{
	int n; cin>>n;
	int A[n];
	for(int i=0;i<n;i++) cin>>A[i];
	sort(A,A+n);

	int target; cin>>target;
	int i=0,j=n-1;
	int p1=-1,p2=-1;
	while(i<j)
	{
		if(A[i]+A[j]==target)
		{
			p1=A[i];
			p2=A[j];
			i++;
			j--;
		}
		else if(A[i] + A[j] > target)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	// i am currently assuming pair exists
	// if it doesnt exist p1 will remain -1
	// Deepak should buy roses whose prices are 40 and 40.

	cout<<"Deepak should buy roses whose prices are "<<p1<<" and "<<p2<<"."<<endl;
}
int main() {
	int t; 
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}