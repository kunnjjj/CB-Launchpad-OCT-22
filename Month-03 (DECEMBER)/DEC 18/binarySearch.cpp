#include<iostream>
using namespace std;


int binarySearch(int *A,int n,int key)
{
    int s=0,e=n-1;

    while(s<=e)
    {
        int mid=(s+e)/2;
        if(A[mid]==key)
        {
            return mid;
        }

        if(A[mid] > key)
        {
            e=mid-1;    
        }
        else
        {
            s=mid+1;
        }
    }
    return -1;
}

int main()
{
    int n; cin>>n;
    int A[n];

    for(int i=0;i<n;i++) cin>>A[i]; // assuming sorted array

    int key; cin>>key;
    cout<<binarySearch(A,n,key)<<endl;

    return 0;
}