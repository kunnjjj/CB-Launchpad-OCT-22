#include<iostream>
using namespace std;

int main()
{
    pair<string,int> car1;
    car1.first="BMW";
    car1.second=48382;

    cout<<"car1.first: "<<car1.first<<endl;
    cout<<"car1.second: "<<car1.second<<endl;

    pair<pair<string,string>,int> p2;
    p2.first.first="abc";
    p2.first.second="PRQ";
    p2.second=570;

    return 0;
}