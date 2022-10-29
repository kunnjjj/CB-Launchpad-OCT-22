#include <iostream>
using namespace std;

int main()
{
    cout << "output by while: " << endl;
    int i = 1, j = 10;
    while (i <= j)
    {
        cout << "hello " << endl;
        i = i + 1, j = j - 1;
    }

    cout << "output by for" << endl;
    for (i = 1, j = 10; i <= j; i = i + 1, j = j - 1)
    {
        cout << "hello" << endl;
    }

    cout << "output by do while" << endl;
    i = 1, j = 10;
    do
    {
        cout<<"hello"<<endl;
        i=i+1,j=j-1;
    } while (i<=j);

    return 0;
}