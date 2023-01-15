#include<iostream>
using namespace std;

void printSubsequence(string ip,string op)
{
    if(ip.empty())
    {
        cout<<op<<endl;

        return ;
    }

    // INCLUDE
    printSubsequence(ip.substr(1),op + ip[0]) ; //ip="kunj" -> ip.substr(1)="unj"
    // EXCLUDE
    printSubsequence(ip.substr(1),op);
}   


int main()
{

    string ip;
    cin>>ip;
    cout<<"-----------------------"<<endl;

    printSubsequence(ip,"");


    return 0;
}