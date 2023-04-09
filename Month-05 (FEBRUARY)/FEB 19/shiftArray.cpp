#include<iostream>
#include<vector>
using namespace std;


void shift(vector<int> &A)
{
    int n=A.size();
    int last_ele=A[n-1];
    for(int i=n-1;i>=1;i--)
    {
        A[i]=A[i-1];
    }
    A[0]=last_ele;
}

int main()
{

    int n; cin>>n;
    vector<int> A(n);

    for(int &x:A) cin>>x;

    shift(A);
    for(int Yx:A) cout<<Yx<<" ";


}