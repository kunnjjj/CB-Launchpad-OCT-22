#include<iostream>
using namespace std;


void merge(int L,int R,int *A)
{
    int C[R-L+1];
    int pos=0;
    int mid=(L+R)/2;
    int i=L,j=mid+1;

    while(i<=mid && j<=R)
    {
        if(A[i]<=A[j])
        {
            C[pos++]=A[i++];
            // C[pos]=A[i];
            // i++;
            // pos++;
        }
        else
        {
            C[pos++]=A[j++];
        }
    }

    while(i<=mid) C[pos++]=A[i++];
    while(j<=R) C[pos++]=A[j++];


    pos=0;
    for(int k=L;k<=R;k++)
    {
        A[k]=C[pos++];
    }    
}
void mergeSort(int L,int R,int *A) 
{
    if(L>=R) return ;
    int mid=(L+R)/2;
    
    mergeSort(L,mid,A);
    mergeSort(mid+1,R,A);
    merge(L,R,A);
}

int main()
{

    int A[]={8,7,1,4,3,2,8,6};

    int n=sizeof(A)/sizeof(int);

    mergeSort(0,n-1,A);

    for(int i=0;i<n;i++) cout<<A[i]<<", ";
    cout<<endl;
    
    return 0;
}

