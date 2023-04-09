#include<iostream>
using namespace std;

int *func()
{
    int *A=new int[5]; //=new int [5];
    A[0]=1;
    A[1]=2;
    A[2]=3;
    A[3]=4;
    A[4]=5;

    cout<<A<<endl;
    cout<<"inside func: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return A;
}
int main()
{
    int *B=NULL;
    B=func();
    cout<<"in main: "<<endl;
    cout<<B<<endl;
 
    for(int i=0;i<5;i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<endl;

    delete [] B; // frees the memory

    // int *x=new int;
    // (*x)=5;
    // (*x)++;
    // cout<<(*x)<<endl;
    // delete x;


    B=new int[10];

    cout<<"new allocated memory"<<endl;
    cout<<&B[0]<<endl;




    // MEMORY LEAK, jab kisi location ka address hum bhool jaye


    int A[3];

    cout<<"size of A: "<<sizeof(A)<<endl;

    cout<<"size of B: "<<sizeof(B)<<endl;
    delete[] B;


    return 0;
}