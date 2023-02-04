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

void insertAtHead(node*& head,node*& tail,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        tail=head;
        return ;
    }
    node *nayiNode=new node(data);
    nayiNode->next=head;
    head=nayiNode;
}

void insertAtTail(node*& head,node*& tail,int data)
{
    if(head==NULL)
    {
        insertAtHead(head,tail,data);
        return ;
    }
    tail->next=new node(data);
    tail=tail->next;
}

void print(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
} 

int main()
{
    node* head=NULL;
    node* tail=NULL;

    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int d; cin>>d;
        insertAtTail(head,tail,d);
    }


    print(head);

    return 0;
}