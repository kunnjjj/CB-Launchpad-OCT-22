#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 1; // n=5

    while (i <= n)
    {
        // i=3,n=5
        int j = 1;
        while (j < i)
        {
            cout << " ";
            j = j + 1;
        }

        j = i;
        while (j <= n)
        {
            cout << j;
            j = j + 1;
        }

        j = n - 1;
        while (j >= i)
        {
            cout << j;
            j = j - 1;
        }
        // cout<<"\n";
        cout << endl;
        i = i + 1;
    }
    i = n - 1;
    while (i >= 1)
    {
        int j = 1;
        while (j < i)
        {
            cout << " ";
            j = j + 1;
        }

        j = i;
        while (j <= n)
        {
            cout << j;
            j = j + 1;
        }

        j = n - 1;
        while (j >= i)
        {
            cout << j;
            j = j - 1;
        }
        // cout<<"\n";
        cout << endl;

        i = i - 1;
    }

    // i=1;

    // while(i<=n-1)
    // {
    //     //kaam
    //     int j=1;
    //     while(j<=n-i-1)
    //     {
    //         cout<<" ";
    //         j=j+1;
    //     }

    //     while(j<=n)
    //     {
    //         cout<<j;
    //         j=j+1;
    //     }
    //     j=n-1;
    //     while(j>=n-i)
    //     {
    //         cout<<j;
    //         j=j-1;
    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

    return 0;
}