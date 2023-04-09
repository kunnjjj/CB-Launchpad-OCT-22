#include<iostream>
using namespace std;


bool isSortedReverse(int *A,int n) // tell me whether A[0....n-1] is sorted or npt
{
    if(n==1) // here n works as size 
    {
        // yadi main se isSortedReverse(A,n-1) use n=0
        // yahi main se iSortedReverse(A,n) use n=1 
        return true;
    }

    return A[n-2]<=A[n-1] && isSortedReverse(A,n-1);
    // if(A[n-2]<=A[n-1])
    // {
    //     return isSortedReverse(A,n-1);
    // }
    // else
    // {
    //     return false;
    // }
}
bool isSortedAlternate(int *A,int n)
{
    if(n==1)
    {
        return true;
    }
    return A[0]<=A[1] && isSortedAlternate(A+1,n-1);
}

int main()
{




    return 0;
}