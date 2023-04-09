#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    for (int i = 2; i <= n; i = i + 1)
    {
        bool is_prime = true;
        for (int j = 2; j*j<= i; j = j + 1)
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
        }
        // jab mein above loop ke bahar aaunga
        // then is is_prime is true then i was prime
        // else i was not prime
        if (is_prime)
        {
            cout << i << endl;
        }
        
    }

    return 0;
}