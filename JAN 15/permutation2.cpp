#include<iostream>
using namespace std;

void generatePermutations(string &s,int i,int &cnt)
{

    if(i==(int)s.size())
    {
        cout<<s<<endl;
        cnt++;
        return ;
    }


    for(int j=i;j<(int)s.size();j++)
    {
        swap(s[i],s[j]);
        generatePermutations(s,i+1,cnt);
    }
}

int main()
{
    string s; cin>>s;
    int cnt=0;
    generatePermutations(s,0,cnt);
    cout<<"cnt: "<<cnt<<endl;



    return 0;
}