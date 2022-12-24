#include<iostream>
using namespace std;


int sumOfDigits(int n)
{
    if(n==0)
    {
        return 0;
    }

    int dig=n%10;
    int sumOfRemaining=sumOfDigits(n/10);

    return dig + sumOfRemaining;
}
int main()
{



    return 0;
}