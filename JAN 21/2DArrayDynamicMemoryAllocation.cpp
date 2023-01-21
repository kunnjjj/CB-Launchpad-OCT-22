#include <iostream>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;

    int **A = new int *[r];
    // dataype *ptr=new datatype[size];
    // here datatype=int*

    for (int i = 0; i < r; i++)
    {
        A[i] = new int[c];
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << A[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}