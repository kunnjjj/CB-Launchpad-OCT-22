#include <iostream>
using namespace std;

void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main()
{

    int A[] = {5, 1, 6, 8, 4, 3, 2};
    int n = sizeof(A) / sizeof(int);

    cout << "n: " << n << endl;

    for (int i = 0; i <= n - 2; i++)
    {
        int small = A[i], idx = i;
        for (int j = i; j < n; j++) // j can be initialised with i+1 too
        {
            if (A[j] < small)
            {
                small = A[j];
                idx = j;
            }
        }
        swap(A[i], A[idx]); // index of smallest element is stored in 'idx'
        cout << "Pass: " << i << endl;
        print(A, n);
    }

    return 0;
}