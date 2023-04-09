#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<1<<endl;
    int i=2;
    while(i<=n)
    {
        cout<<i-1;

        int j=1;
        while(j<=i-2)
        {
            cout<<0;
            // j=j+1;
            j+=1;
        }
        cout<<i-1<<endl;
        i+=1;
        // i=i*2; i*=2;
        // i=i/5; i/=5
    }

    return 0;
}