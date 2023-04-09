#include <iostream>
using namespace std;
int main()
{
    int a, b;

    cin >> a >> b;

    // cin >> b;
    int hcf;

    int i = 1;
    while (i <= a && i <= b)
    {
        if (a % i == 0 && b % i == 0)
        {
            hcf = i;
        }
        i = i + 1;
    }

    // cout<<a<<b<<"\n";
    // cout<<a;
    // cout<<b;

    // cout<<a << b<<"\n";
    cout<<"hcf is: "<<hcf<<endl;


    return 0;
}