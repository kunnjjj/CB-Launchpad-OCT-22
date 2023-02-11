#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int d)
    {
        data=d;
        next=NULL;
    }
};


class Stack
{
    public:
    node* head;

    Stack()
    {
        head=NULL;
    }

    void push(int data)
    {
        if(head==NULL)
        {
            head=new node(data);
            return ;
        }
        node* nayiNode=new node(data);
        nayiNode->next=head;
        head=nayiNode;
    }

    void pop()
    {
        if(head==NULL)
        {
            cout<<"underflow"<<endl;
            return ;
        }
        node* temp=head;
        head=head->next;
        delete(temp);
    }
    int top()
    {
        if(head==NULL)
        {
            cout<<"underflow"<<endl;
            return -1;
        }
        return head->data;
    }
    void reverse()
    {
        if(head==NULL or head->next==NULL)
        {
            return ;
        }

        node* prev=NULL;
        node* cur=head;
        while(cur!=NULL)
        {
            node* agla=cur->next;
            cur->next=prev;
            prev=cur;
            cur=agla;
        }
        head=prev;
    }
    void print()
    {
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main()
{

    Stack S;
    S.push(4);
    S.push(5);
    S.print();
    S.reverse();
    S.print();

    // Stack<string> S2;
    // S2.push("abc");
    // S2.push("pqr");
    // S2.push("djdjd");
    // S2.push("ankushKumar");

    // S2.print();
    // S2.reverse();
    // S2.print();

    return 0;
}
