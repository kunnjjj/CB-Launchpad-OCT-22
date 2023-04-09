#include<iostream>
using namespace std;
void permutations(string ip,string op)
{   
    if(ip.empty())
    {
        cout<<op<<endl;
        return ;
    }

    for(int i=0;i<(int)ip.size();i++)
    {
        swap(ip[0],ip[i]);
        permutations(ip.substr(1),op+ip[0]);
        swap(ip[0],ip[i]);
    }
}





int main()
{

    string ip; cin>>ip;
    cout<<"-----------------------"<<endl;

    permutations(ip,"");


    return 0;
}