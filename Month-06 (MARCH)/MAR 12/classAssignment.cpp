#include <iostream>
#include <vector>
using namespace std;

int maxLen = 25;
vector<vector<int>> dp(maxLen + 1, vector<int>(2, -1));

int cnt(int k, int dig)
{
    if (k == 1)
    {
        return 1;
    }
    if (dp[k][dig] != -1)
    {
        return dp[k][dig];
    }
    // cnt(k,0)= len of string=k, ends in 'a'
    // cnt(k,1)= len of string=k, ends in 'b'

    // cnt(k,0) = cnt(k-1,0) + cnt(k-1,1)
    // cnt(k,1) = cnt(k-1,0)
    if (dig == 0)
    {
        return dp[k][dig] = cnt(k - 1, 0) + cnt(k - 1, 1);
    }
    else
    {
        return dp[k][dig] = cnt(k - 1, 0);
    }
}
int main()
{

    int t;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        int n;
        cin >> n;
        // cout<<cnt(n,0) + cnt(n,1)<<endl; // total number of strings

        vector<vector<int>> CNT(n + 1, vector<int>(2));

        // CNT[i][0]= len of string='i' , ending in [0]
        // CNT[i][1]= len of string='i' , ending in [1]

        // CNT[i][0]= CNT[i-1][0] + CNT[i-1][1]
        // CNT[i][1]= CNT[i-1][0]

        CNT[1][0] = 1;
        CNT[1][1] = 1;

        for (int i = 2; i <= n; i++)
        {

            CNT[i][0] = CNT[i - 1][0] + CNT[i - 1][1];
            CNT[i][1] = CNT[i - 1][0];
        }
        cout<<"#"<<test<<" : ";
        cout<<CNT[n][0] + CNT[n][1]<<endl;
    }

    return 0;
}