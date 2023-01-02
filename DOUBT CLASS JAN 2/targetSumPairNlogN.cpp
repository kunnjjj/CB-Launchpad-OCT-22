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
        // binary search i+1....n-1
        int rem=target- A[i];
        int s=i+1,e=n-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(A[mid]==rem)
            {
                cout<<A[i]<<" and "<<A[mid]<<endl;
                break;
            }
            if(A[mid] < rem)
            {
                // we may find value in mid+1,,,,e
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
    }



    return 0;
}