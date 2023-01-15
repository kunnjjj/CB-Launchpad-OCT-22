#include <iostream>
using namespace std;

string arr[] = {"zero",
                "one",
                "two",
                "three",
                "four",
                "five",
                "six",
                "seven",
                "eight",
                "nine"};
void recFunc(string t,string op)
{
    if(t.empty())
    {
        cout<<"our op string is: "<<op<<endl;
        return ;
    }

    int dig=t[0]-'0';
    recFunc(t.substr(1),op+arr[dig]);
}

int main()
{
    string t;
    cin >> t;

    recFunc(t,"");

    // string opInMain="";
    // for(int i=0;i<(int)t.size();i++)
    // {
    //     int dig=t[i]-'0';
    //     opInMain+=arr[dig];
    // }
    // cout<<opInMain<<endl;

    return 0;
}