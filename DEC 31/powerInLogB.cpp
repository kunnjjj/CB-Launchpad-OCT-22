#include<iostream>
using namespace std;



int powerRecursive(int a,int b) // we need a^b // (this is exponentiation for explanation)
{   
    if(b==0) return 1;
    int halfPower= powerRecursive(a,b/2);

    if(b&1)
    {
        return a * halfPower * halfPower;
    }   
    else
    {
        return halfPower * halfPower;
    }
}