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
    

    for(int pass=0;pass<=n-2;pass++)
    {
        for(int j=0;j<=n-2-pass;j++)
        {
            if(A[j] > A[j+1]) //
            {
                swap(A[j],A[j+1]); // swap bubbles if current bubble is biger
            } 
        }
        cout<<"pass: "<<pass<<endl;
        print(A,n);
    }



    return 0;
}