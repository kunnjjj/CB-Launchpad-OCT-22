#include <iostream>
#include <vector>
using namespace std;

// n=10^5

int maxN = 1e5;
// vector<bool> visited(maxN + 1);
vector<int> dp(maxN+1,-1);
// state: is particular N ki value par aaya hun ya nahi

// visited[i]=true mein ith state par aa chuka hu, false: abhi nahi aaya hu

// set dp[n] with any invalid value, say -1

// dp[n]==-1, this state was never reached
// dp[n]!=-1  this state was reached

int fib(int n)
{
    if (n == 0 || n == 1)
        return dp[n]=n;

    if(dp[n]!=-1)
    {
        return dp[n];
    }
    // else false
    // visited[n]=true;
    // dp[n]=fib(n - 1) + fib(n - 2);
    // return dp[n];
    return dp[n]=fib(n-1) + fib(n-2);
}




int main()
{

    int n;
    cin >> n;
    cout << fib(n) << endl;
    // int y=6;
    // int x= 4 + (y=7);


    vector<int> FIB(maxN+1);

    FIB[0]=0;
    FIB[1]=1;

    for(int i=2;i<=n;i++)
    {
        FIB[i]=FIB[i-1] + FIB[i-2];
    }
    cout<<FIB[n];



    return 0;
}