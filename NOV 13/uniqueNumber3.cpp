

#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int A[n];

	for(int i=0;i<n;i++) cin>>A[i];

	int freq[31]={0};
	// for(int i=0;i<=30;i++)
	// {
	// 	freq[i]=0;
	// }

	for(int j=0;j<n;j++)
	{
		int cur_num=A[j];
		
		for(int i=0;i<=30;i++)
		{
			// if the ith bit of cur_num is =1 
			// then increase ith index of freq by 1

			if((cur_num&(1<<i))>0) // other method ((cur>>i)&1)==1
			{
				freq[i]++;
			}
		}
	}

	int ans=0;
	for(int i=0;i<=30;i++)
	{
		if(freq[i]%3==1)
		{
			// ith bit of unique number is found we will add (1<<i) to ans;
			ans+=(1<<i);
		}
	}

	cout<<ans<<endl;
	return 0;
}