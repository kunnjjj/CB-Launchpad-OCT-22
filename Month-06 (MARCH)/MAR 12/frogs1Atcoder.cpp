// https://atcoder.jp/contests/dp/tasks/dp_a
#include <bits/stdc++.h>
using namespace std;
 
vector<int> dp((int)1e5 + 1, 0);
 
int cost(int i, vector<int> &A)
{
    if (i == 0)
    {
        return 0;
    }
    // if(i<0) // invalid
    // {
    //     return 1e9;
    // }
    if (dp[i] != -1)
        return dp[i];
 
    int op1 = 1e9, op2 = 1e9;
    if (i - 1 >= 0)
    {
        op1 = abs(A[i] - A[i - 1]) + cost(i - 1, A);
    }
    if (i - 2 >= 0)
    {
        op2 = abs(A[i] - A[i - 2]) + cost(i - 2, A);
    }
    return dp[i] = min(op1, op2);
}
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &x : A)
        cin >> x;
 
    // cout<<cost(n-1,A)<<endl;
    dp[0] = 0;
 
    for (int i=1;i<n;i++)
    {
        // dp[i] min cost to get to i starting from 0
        // 0.....i
        int op1 = 1e9, op2 = 1e9;
        if (i - 1 >= 0)
        {
            op1 = abs(A[i] - A[i - 1]) + dp[i-1];
        }
        if (i - 2 >= 0)
        {
            op2 = abs(A[i] - A[i - 2]) + dp[i-2];
        }
        dp[i] = min(op1, op2);
    }
    cout<<dp[n-1]<<endl;
 
    return 0;
}