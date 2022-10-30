#include<iostream>
#include<climits>
using namespace std;

int main()
{

    cout<<"INT_MAX: "<<(INT_MAX)<<endl;
    cout<<"LLONG_MAX: "<<(LLONG_MAX)<<endl;
    cout<<"INT_MIN: "<<(INT_MIN)<<endl;
    cout<<"LLONG_MIN: "<<LLONG_MIN<<endl;



    long long x=LLONG_MAX;
    cout<<x<<endl;

    long int y=24;
    cout<<"size of long int: "<<sizeof(y)<<endl;


    return 0;
}