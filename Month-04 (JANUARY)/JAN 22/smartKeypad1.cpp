#include<iostream>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

// From <https://hack.codingblocks.com/app/contests/3616/742/problem> 

void func(int pos,string &input,string &op)
{
    if(pos==(int)input.size())
    {
        cout<<op<<endl;
        return ;
    }

    int dig=input[pos]-'0';
    for(int i=0;i<(int)table[dig].size();i++)
    {
        char ch=table[dig][i];
        op.push_back(ch);
        func(pos+1,input,op);
        op.pop_back(); // BACK TRACKING
    }
}


int main()
{
    string input; cin>>input;
    string op;
    func(0,input,op);
    return 0;
}