#include <iostream>
#include <vector>
using namespace std;

int mod_add(int a, int b, int M = (int)1e9 + 7)
{
    return (a % M + b % M) % M;
}

int mod_mul(int a, int b, int M = (int)1e9 + 7)
{
    return (1LL * a % M * b % M) % M;
}

int main()
{

    int t;
    cin >> t;
    int MAX_N = 1e6;
    vector<vector<int>> CNT(MAX_N + 1, vector<int>(2));

    // CNT[k][0]= tower of len=k, and no slit at top
    // CNT[k][1]= tower of len=k, and has slit at top

    CNT[1][0] = 1;
    CNT[1][1] = 1;

    for (int k = 2; k <= MAX_N; k++)
    {
        CNT[k][1] = mod_add(CNT[k - 1][0], mod_mul(4, CNT[k - 1][1]));
        CNT[k][0] = mod_add(mod_mul(2, CNT[k - 1][0]), CNT[k - 1][1]);
    }
    while (t--)
    {
        int n;
        cin >> n;
        cout<<mod_add(CNT[n][0],CNT[n][1])<<endl;
    }

    return 0;
}