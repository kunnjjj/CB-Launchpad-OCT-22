#include<iostream>
using namespace std;

int main()
{
    // char A[10];

    // A[0]='3';
    // A[1]='#';
    // A[2]='x';

    // cout<<A[0]<<endl;
    // cout<<A[2]<<endl;

    // cout<<&A[0]<<endl;

    // A[3]='\0';

    // cout<<&A[0]<<endl;

    // char B[10]={'A','B','C','D','\0','2','3'};
    // cout<<&B[0]<<endl;
    // cout<<B<<endl;
    // char C[5]="ABCD";
    // cout<<C<<endl;

    // // cout<<(float*)&C[0]<<endl;
    // cout<<&C[0]<<endl;
    

    // int *ptr1;
    // char *ptr2;

    // cout<<"size of ptr1: "<<sizeof(ptr1)<<endl;
    // cout<<"size of ptr2: "<<sizeof(ptr2)<<endl;


    char D[100];
    // cin>>D;
    // cout<<D<<endl;
    // cin >> x;
    cin.getline(D,100,'#'); // doesnt ignore white space 
    cout<<D<<endl;

    char ch=getchar();
    cout<<ch<<endl;
    // read about getline(), getchar(), getch(), gets() etc...
    // from cppreference/gfg/ etc.....

    return 0;
}