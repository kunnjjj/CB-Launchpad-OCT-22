#include<iostream>
using namespace std;


void multiply(int A[],int x,int &idx)
{
	int carry=0;
	for(int i=0;i<=idx;i++)
	{
		int res=A[i] * x + carry;
		A[i]=res%10;
		carry=res/10;
	}
	while(carry>0)
	{
		idx++;
		A[idx]=carry%10;
		carry=carry/10;
	}
}


int main() {
	int n;
	cin>>n;

	int A[999]={0};

	A[0]=1;
	int idx=0;
	for(int i=1;i<=n;i++)
	{
		multiply(A,i,idx);
	}

	for(int i=idx;i>=0;i--)
	{
		cout<<A[i];
	}

	return 0;
}