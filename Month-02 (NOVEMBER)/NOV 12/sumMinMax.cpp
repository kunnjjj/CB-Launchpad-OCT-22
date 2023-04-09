#include<iostream>
#include<climits>

using namespace std;
int main()
{
    // cout<<INT_MAX<<endl;


    int n; cin>>n;
    int A[n];

    for(int i=0;i<n;i++) cin>>A[i];

    int sum=0,mx=INT_MIN,mn=INT_MAX;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if(A[i] > mx)
        {
            mx=A[i];
        }
        if(A[i] < mn)
        {
            mn=A[i];
        }
    }
    cout<<"mn: "<<mn<<endl;
    cout<<"mx: "<<mx<<endl;
    cout<<"sum: "<<sum<<endl;

    return 0;
}