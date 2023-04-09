#include<iostream>
using namespace std;

// int vipin =100;


int main()
{

    // int nayaVar=vipin;

    int vipin=20;
    // cout<<"vipin: "<<vipin<<endl;
    // cout<<"global vipin: "<<nayaVar<<endl;

    for(int i=100;i>0;i=i/10)
    {
        int vipin=10;
        cout<<"vipin is: "<<vipin<<endl;
        // cout<<"main wala vipin: "<<::vipin<<endl;
        cout<<"kuch nahi padha"<<endl;
        cout<<"i is: "<<i<<endl;
    }
    cout<<"vipin is: "<<vipin<<endl;


    int n;
    cin>>n;
    int sum=0;


    int i=n;
    while(i>0)
    {
        sum+=i%10;
        i/=10;
    }

    cout<<sum<<endl;

    // i=n;
    // sum=0;
    for(i=n,sum=0;i>0; i/=10)
    {
        sum+=i%10;
    }
    cout<<sum<<endl;


    i=n,sum=0;
    do
    {
        sum+=i%10;
        i/=10;
        /* code */
    } while (i>0);
    cout<<sum<<endl;

    return 0;
}