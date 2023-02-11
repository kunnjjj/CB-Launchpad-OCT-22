#include<iostream>
#include<stack>
using namespace std;

void reverseStackUsingMoreStacks(stack<int> &s)
{
    
    stack<int> a,b;

    while(!s.empty())
    {
        int ele=s.top();
        a.push(ele);
        s.pop();
    }

    while (!a.empty())
    {
        int ele=a.top();
        b.push(ele);
        a.pop();
    }

    while(!b.empty())
    {
        int ele=b.top();
        s.push(ele);
        b.pop();
    }
}


void print(stack<int> copyStack)
{
    while(!copyStack.empty())
    {
        int ele=copyStack.top();
        copyStack.pop();
        cout<<ele<<" ";
    }
    cout<<endl;
}

void insertAtBottom(stack<int> &s,int ele)
{
    if(s.empty())
    {
        s.push(ele);
        return ;
    }
    int store=s.top();
    s.pop();
    insertAtBottom(s,ele);
    s.push(store);
}
void reverseStackUsingRecursion(stack<int> &s) //T(N)
{
    if(s.empty())
    {
        return ;
    }
    int spl_element=s.top();
    s.pop();
    reverseStackUsingRecursion(s); // T(N-1)
    insertAtBottom(s,spl_element); // //O(N)
}
//T(N)=T(N-1) + O(N)
//T(N)= T(N-2) + O(N-1) + O(N) = O(N^2)
int main()
{
    stack<int> s;
    int n; cin>>n;

    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        s.push(x);
    }
    print(s);
    reverseStackUsingMoreStacks(s);
    print(s);

    return 0;
}