#include<iostream>
using namespace std;
int main() {
	int n; cin>>n;
	int A[n];
	for(int i=0;i<n;i++) 
	{
		cin>>A[i];
	}
	// XOR OF ALL ELEMENTS
	int XOR=0;
	for(int i=0;i<n;i++)
	{
		XOR^=A[i];
	}

	// 'XOR' will be non zero 
	//special bit
	int special_bit=-1;

	for(int i=0;i<=31;i++) // if +ve we can upto 30 (integers)
	{
		if((XOR&(1<<i))>0) // ((XOR>>i)&1)==1
		{
			special_bit=i;
			break;
		}
	}

	// SEGREGATE Array on basis of whether spl bit =1 or not
	int x=0,y=0;
	for(int i=0;i<n;i++)
	{
		int cur_num=A[i];

		if((cur_num&(1<<special_bit))>0)
		{
			x^=cur_num;
		}
		else
		{
			y^=cur_num;
		}
	}
	// PRINT IN ASCENDING ORDER
	cout<<min(x,y)<<" "<<max(x,y)<<endl;
	return 0;
}