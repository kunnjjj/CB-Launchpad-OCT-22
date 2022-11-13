#include<iostream>
#include<cmath>

using namespace std;

int main()
{       
    double eps=1e-7;
    if(abs(0.1 + 0.2-0.3) < eps)
    {
        cout<<"Equal"<<endl;
    }
    else
    {
        cout<<"Not equal"<<endl;
    }



    return 0;
}