#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    string s; cin>>s;
    int n=s.size();
    sort(s.begin(),s.end());
    cout<<s<<endl;
    for(int i=0;i<n;i++)
    {
        if(i==0 || s[i]!=s[i-1])
        {
            cout<<s[i]<<" ";
        }
    }

    return 0;
}