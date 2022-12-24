#include<iostream>
using namespace std;

int fact(int n) // hum tujhse 'n' ka factorial chahte hai
{   
    if(n==0)
    {
        return 1;
    }

    int subProb= fact(n-1);
    return n * subProb;
}

int main()
{

    cout<<fact(5)<<endl;


    return 0;
}