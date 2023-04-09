#include<iostream>
using namespace std;

bool isSorted(int i,int n,int *A) // tell me whether A[i...n-1] is sorted or not
{
    if(i==n-1) // tell me whether A[n-1.....n-1] is sorted or not
    {
        return true;
    } 

    // bool smallerSub=isSorted(i+1,n,A); // tell me whether A[i+1...n-1] is sorted or not
    // if(smallerSub==true)
    // {
    //     if(A[i] <= A[i+1])
    //     {
    //         return true;    
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }
    // else
    // {
    //     return false;
    // }
    return isSorted(i+1,n,A) && A[i]<=A[i+1];
}

bool isSortedOptimised(int i,int n,int *A) // tell me whether A[i...n-1] is sorted or not
{
    if(i==n-1) // tell me whether A[n-1.....n-1] is sorted or not
    {
        return true;
    } 

    // if(A[i]<=A[i+1])
    // {
    //     return isSortedOptimised(i+1,n,A);
    // }
    // else
    // {
    //     return false;
    // }
    return A[i]<=A[i+1] && isSortedOptimised(i+1,n,A); //return (false && something)
}


int main()
{
    int n; cin>>n;
    int A[n];

    for(int i=0;i<n;i++) cin>>A[i];


    if(isSorted(0,n,A))
    {
        cout<<"Yes, Array is Sorted"<<endl;
    }
    else
    {
        cout<<"No, Array is not sorted"<<endl;
    }

    // int *ptr= &A[0];
    // int *ptr = A; where A is some whether


    return 0;
}