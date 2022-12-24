#include<iostream>
using namespace std;

int fib(int n) // tum mujhe fib(n) laakar doge
{   
    if(n==0) return 0;
    if(n==1) return 1;
    // alternatively 
    // if(n<=1) return n;

    int smallerSub1=fib(n-1);
    int smallerSub2=fib(n-2);

    return smallerSub1 + smallerSub2;

}


int main()
{   

    cout<<fib(4)<<endl;

    return 0;
}