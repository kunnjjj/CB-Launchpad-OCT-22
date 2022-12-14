


#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n; cin>>n;
	int A[n];
	int B[n];

	for(int i=0;i<n;i++) cin>>A[i];
	for(int i=0;i<n;i++) cin>>B[i];
	sort(A,A+n);
	sort(B,B+n);
	int i=0,j=0;

	
	int C[n]; // n size because intersection cannot be more than 'n' elements

	// ab kaunsi position bharni baaki hai
	int idx=0; // idx maintains which position of C array has to be filled

	
	while(i<n && j<n)
	{
		if(A[i]==B[j])
		{
			C[idx]=A[i];
			idx++;
			i++;
			j++;
		}
		else if(A[i] < B[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}

	cout<<"[";
	for(int i=0;i<=idx-2;i++)
	{
		cout<<C[i];
		cout<<", ";
	}
	cout<<C[idx-1];
	cout<<"]";



	return 0;
}

// #include<iostream>
// #include<climits>
// using namespace std;
// int main() {
// 	int n; cin>>n;
// 	int A[n];
// 	int B[n];

// 	for(int i=0;i<n;i++) cin>>A[i];
// 	for(int i=0;i<n;i++) cin>>B[i];

// 	int mx1=INT_MIN,mx2=INT_MIN;
// 	for(int i=0;i<n;i++)
// 	{
// 		if(A[i] > mx1)
// 		{
// 			mx1=A[i];
// 		}
// 		if(B[i] > mx2)
// 		{
// 			mx2=B[i];
// 		}
// 	}
// 	// cout<<"max1: "<<mx1<<endl;
// 	// cout<<"max2: "<<mx2<<endl;

// 	// sort(A,A+n) works in O(NlogN)

// 	int freqA[mx1+1]={0};
// 	int freqB[mx2+1]={0};

// 	for(int i=0;i<n;i++)
// 	{
// 		int cur_ele=A[i];
// 		freqA[cur_ele]++;
// 	}

// 	for(int i=0;i<n;i++)
// 	{
// 		int cur_ele=B[i];
// 		freqB[cur_ele]++;
// 	}

// 	int C[n]; // n size because intersection cannot be more than 'n' elements

// 	// ab kaunsi position bharni baaki hai
// 	int idx=0; // idx maintains which position of C array has to be filled

// 	for(int i=0;i<=min(mx1,mx2);i++)
// 	{
// 		int freq_of_i_in_A=freqA[i];
// 		int freq_of_i_in_B=freqB[i];
// 		// cout<<"i: "<<i<<endl;
// 		// cout<<"freq_A[i]: "<<freq_of_i_in_A<<endl;
// 		// cout<<"freq_B[i]: "<<freq_of_i_in_B<<endl;
// 		for(int j=1;j<=min(freq_of_i_in_A,freq_of_i_in_B);j++)
// 		{
// 			C[idx]=i;
// 			idx++;
// 			// C[idx++]=i;
// 		}
// 	}

// 	cout<<"[";
// 	for(int i=0;i<=idx-2;i++)
// 	{
// 		cout<<C[i];
// 		cout<<", ";
// 	}
// 	cout<<C[idx-1];
// 	cout<<"]";



// 	return 0;
// }