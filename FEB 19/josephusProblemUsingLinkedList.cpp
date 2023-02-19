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
        // prev=NULL;
    }
};

void insertAtTail(node* &tail,int x)
{
    tail->next=new node(x);
    tail=tail->next;
}

int main()
{
    node* head=new node(1);
    node* tail=head;
    int n; cin>>n;
    for(int i=2;i<=n;i++)
    {
        insertAtTail(tail,i);
    }
    tail->next=head;

    node* prev=head;
    node* cur=head->next;
    int cur_size=n;

    while(cur_size > 1)
    {
        cout<<cur->data<<" ";
        node* aglaAddress=cur->next;
        prev->next=aglaAddress;
        delete(cur);
        prev=aglaAddress;
        cur=aglaAddress->next;
        cur_size--;
    }
    cout<<cur->data<<" ";
    return 0;
}