// https://hack.codingblocks.com/app/contests/3616/729/problem

#include<iostream>
#include<stack>
using namespace std;

bool is_balanced(string &s)
{
	int n=s.size();
	stack<char> st;

	for(int i=0;i<n;i++)
	{
		if(s[i]=='(' or s[i]=='{' or s[i]=='[')
		{
			st.push(s[i]);
		}
		else if(s[i]==')')
		{
			if(!st.empty() && st.top()=='(')
			st.pop();
			else return false;
 		}
		else if(s[i]==']' )
		{
			if(!st.empty() && st.top()=='[')
			st.pop();
			else return false;
		}
		else if(s[i]=='}' )
		{
			if(!st.empty() && st.top()=='{')
			st.pop();
			else return false;
		}
		else
		{

		}
	}
	return st.empty();
}

int main()
{
	string s; cin>>s;

	if(is_balanced(s))
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}


	return 0;
}