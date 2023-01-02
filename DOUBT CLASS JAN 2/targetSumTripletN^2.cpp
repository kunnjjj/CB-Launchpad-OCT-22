#include<iostream>
#include<algorithm>
using namespace std;

int main()
{	
	int n; cin>>n;
	int A[n];
	for(int i=0;i<n;i++) cin>>A[i];

	int target; cin>>target;
	sort(A,A+n);

	for(int k=0;k<n;k++)
	{
		int rem=target-A[k];
		int i=k+1,j=n-1;
		while(i<j)
		{
			if(A[i]  +A[j]==rem)
			{
				cout<<A[k]<<", "<<A[i]<<" and "<<A[j]<<endl;
				i++;
				j--;
			}
			else if(A[i] + A[j] < rem) i++;
			else j--;
		}
	}


	return 0;
}