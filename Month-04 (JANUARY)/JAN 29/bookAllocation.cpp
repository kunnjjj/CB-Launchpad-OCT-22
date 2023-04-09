#include<iostream>
#include<vector>
using namespace std;

bool can_boards_be_painted(vector<int>&boards,int k,long long max_time)
{
    int painter=1; // abhi kaunsa painter use horaha hai
    long long abhi_tak=0; // running sum

    for(int i=0;i<(int)boards.size();i++)
    {
        if(abhi_tak + boards[i]<=max_time)
        {
            abhi_tak+=boards[i];
        }
        else
        {
            painter++;
            abhi_tak=boards[i];
            if(painter > k)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
	int test_case; cin>>test_case;
	while(test_case--){
    int n,k; cin>>n>>k;
    int t=1;
    vector<int> boards(n);
    for(int i=0;i<n;i++) cin>>boards[i];

    long long MAX=0,sum=0;
    for(int i=0;i<n;i++)
    {
        MAX=max(MAX,(long long)boards[i]); 
        sum+=boards[i];
    }

    // long long ans=sum;
    // for(long long max_time=MAX;max_time<=sum;max_time++) // O(SUM)
    // {
    //     if(can_boards_be_painted(boards,k,max_time)) //O(N)
    //     {
    //         ans=max_time;
    //         break;
    //     }
    //     // else
    //     // {

    //     // }
    // }
    // cout<<ans*t<<endl; // ans* time_per_unit
    long long s=MAX,e=sum;
    long long ans=sum;
    while(s<=e)
    {
        long long mid=(s+e)/2;
        if(can_boards_be_painted(boards,k,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    cout<<(ans)<<endl;
	}
    return 0;
}