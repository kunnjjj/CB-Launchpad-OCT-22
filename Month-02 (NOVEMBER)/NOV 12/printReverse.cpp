#include<iostream>
using namespace std;


int main()
{
    int n; 
    cin >> n;

    int A[n];

    for(int idx=0;idx <= n-1;idx++)
    {
        cin >> A[idx];
    }

    for(int idx=n-1;idx>=0;idx--)
    {
        cout<<A[idx]<<" ";
    }
    

    // int arr[3];
    // cout<<arr[2]<<endl; // garbage value
    
    return 0;
}