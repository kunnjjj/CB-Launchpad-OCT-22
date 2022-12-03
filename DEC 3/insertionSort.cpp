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
    int n; cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];


    for (int i = 1; i < n; i++)
    {
        int j = i - 1, key = A[i];
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
        cout<<"current_idx: "<<i<<endl;
        print(A,n);
    }

    return 0;
}
