#include<iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int i=n;
    while (i>=1)
    {

        int j=1;
        while (j<=n-i)
        {
            cout<<" ";
            j=j+1;
        }
        j=1;
        while (j<=2*i-1)
        {
            cout<<"*";
            j=j+1;
            /* code */
        }
        cout<<endl;
        i=i-1;
    }

    i=2;
    while (i<=n)
    {

        int j=1;
        while (j<=n-i)
        {
            cout<<" ";
            j=j+1;
        }
        j=1;
        while (j<=2*i-1)
        {
            cout<<"*";
            j=j+1;
            /* code */
        }
        cout<<endl;
        i=i+1;
    }


    // stars=2*n-1

    // stars=stars-2

    // space=0
    // space=space+1
    
        // int i=3;
        // int j=1;
        // while (j<=n-i)
        // {
        //     cout<<" ";
        //     j=j+1;
        // }
        // j=1;
        // while (j<=2*i-1)
        // {
        //     cout<<"*";
        //     j=j+1;
        //     /* code */
        // }
        // cout<<endl;

    return 0;
}