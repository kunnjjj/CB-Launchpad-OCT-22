#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int A[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    int freq[(int)1e5 + 1];

    for (int i = 0; i < n; i++)
    {
        int cur = A[i];
        freq[cur]++;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int money;
        cin >> money;
        int k;
        cin >> k;

        int cnt = 0;
        for(int i=1;i*i<=money;i++)
        {
            if(money%i==0)
            {
                int other=money/i;
                cnt+=freq[i];   
                if(other!=i)
                cnt+=freq[other];

            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     if(money%A[i]==0) cnt++;
        // }

        if(cnt>=k)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }

    return 0;
}