#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int A[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    int freq[101]={0}; // assuming max element is upto 100 

    for(int i=0;i<n;i++)
    {
        int cur=A[i];
        freq[cur]++;
    }
    

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        int cnt = freq[x];
        // for (int i = 0; i < n; i++)
        // {
        //     if (A[i] == x)
        //         cnt++;
        // }

        cout << cnt << endl;
    }

    return 0;
}