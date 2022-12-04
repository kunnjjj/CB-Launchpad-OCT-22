#include<iostream>
using namespace std;

int main()
{
    int A[]={4,2,10,24};
    cout<<"address of 0th location of A: "<<&A[0]<<endl;
    // for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<"printing A only: "<<A<<endl;

    int *ptr=&A[0];
    cout<<"printing ptr: "<<ptr<<endl;

    cout<<"address of 0th location of A: "<<&A[0]<<endl;
    cout<<"&A[1]: "<<&A[1]<<endl;
    cout<<"(A+1): "<<(A+1)<<endl;
    cout<<"(ptr+1): "<<(ptr+1)<<endl;
    cout<<"*(ptr+1): "<<*(ptr+1)<<endl;
    int B[]={4,5,10,49,10,2,6,8};
    int *ptr_2=&B[0];
    int &temp=B[3];
    temp++;
    ptr_2++;
    (*ptr_2)++;
    ptr_2++;
    ptr_2++;
    (*ptr_2)++;
    ptr_2--;
    (*ptr_2)++;
    // int sizeOfB=sizeof(B)/sizeof(int);
    int sizeOfB=8;
    for(int i=0;i<sizeOfB;i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<endl;
    


    return 0;
}