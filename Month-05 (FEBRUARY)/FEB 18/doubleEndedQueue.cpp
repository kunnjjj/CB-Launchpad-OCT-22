#include<iostream>
using namespace std;


class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }
};

class Deque
{   
    node* head;
    node* tail; // head and tail are fake nodes which do contain data values, 
    // used for cleaner implementation
public:

    Deque()
    {
        head=new node(-1);
        tail=new node(-1);
        head->next=tail;
        tail->prev=head;
    }

    void push_front(int x)
    {
        node* agliNode=new node(x);
        agliNode->next=head->next;
        agliNode->prev=head;
        (head->next)->prev=agliNode;
        head->next=agliNode;
    }

    void pop_front()
    {
        if(head->next==tail) 
        {
            cout<<"underflow"<<endl;
            return ;
        }
        node* temp=head->next;
        head->next=temp->next;
        temp->next->prev=head;
        delete(temp);
    }

    int front()
    {
        if(head->next==NULL)
        {
            cout<<"underflow"<<endl;
            return -1;
        }
        return head->next->data;
    }

    // do push_back
    // do pop_back
};

int main()
{
    Deque q;
    for(int i=0;i<5;i++)
    {
        q.push_front(i+1);
    }

    for(int i=0;i<6;i++)
    {
        cout<<q.front()<<endl;
        q.pop_front();
    }

    return 0;
}