#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int i = n;
    while (i > 0)
    {
        int j = 1;
        while (j <= i - 1)
        {
            cout << " ";
            j = j + 1;
        }

        cout << "*";

        j = 1;
        while (j <= n - 2)
        {
            if (i == 1 || i == n)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
            j = j + 1;
        }
        cout << "*" << endl;
        // cout<<endl;
        i -= 1;
        /* code */
    }

    return 0;
}