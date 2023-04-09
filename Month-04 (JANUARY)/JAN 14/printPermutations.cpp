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
        string ROS=ip.substr(0,i) + ip.substr(i+1);
        permutations(ROS,op+ip[i]);
    }

}

int main()
{

    string ip; cin>>ip;
    cout<<"-----------------------"<<endl;

    permutations(ip,"");


    return 0;
}