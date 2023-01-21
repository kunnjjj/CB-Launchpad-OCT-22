#include<iostream>
using namespace std;

void quickSort(int *A,int s,int e)
{
    if(s>=e) // either one or zero elements are left
    {
        return ;
    }
    int idx=s;
    int pivot=A[e];
    for(int j=s;j<=e-1;j++)
    {
        if(A[j] <= pivot)
        {
            swap(A[j],A[idx]);
            idx++;
        }
    }
    swap(A[idx],A[e]);
    quickSort(A,s,idx-1);
    quickSort(A,idx+1,e); 
}

int main()
{
    int n; cin>>n;
    // int A[n];
    int *A=new int[n]{0};

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    quickSort(A,0,n-1);
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<endl;

    return 0;
}