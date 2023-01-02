#include<iostream>
#include<algorithm>
using namespace std;
// O(N) after sorting

int main()
{
    int n; cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];

    int target; cin>>target;

    sort(A,A+n);

    int i=0,j=n-1;
    while(i<j) // 1: i<j 2: i<=j
    {
        if(A[i] + A[j]==target)
        {
            cout<<A[i]<<" and "<<A[j]<<endl;
            i++;
            j--;
        }
        else if(A[i] + A[j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }


    return 0;
}