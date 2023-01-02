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

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			//binary search j+1....n-1
			int s=j+1,e=n-1;
			int rem=target- (A[i] + A[j]);
			while(s<=e)
			{
				int mid=(s+e)/2;
				if(A[mid]==rem)
				{
					cout<<A[i]<<", "<<A[j]<<" and "<<A[mid]<<endl;
					break;
				}
				if(A[mid] < rem) s=mid+1;
				else e=mid-1;
			}
		}
	}


	return 0;
}