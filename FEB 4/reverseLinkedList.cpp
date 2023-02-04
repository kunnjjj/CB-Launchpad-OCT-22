#include <iostream>
using namespace std;

class node
{
public:
    int data;

    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};


void insertAtTail(node*& head,int d)
{
    if(head==NULL){
        head=new node(d);
        return ;
    }
    insertAtTail(head->next,d);
}

void print(node* head)
{
    if(head==NULL) 
    {
        cout<<endl;
        return ;
    }
    cout<<head->data<<" ";
    print(head->next);
}

node* reverseList(node* head)
{
    if(head==NULL or head->next==NULL) return head;

    node* prev=NULL,*cur=head;

    while(cur!=NULL)
    {
        node* agla_node=cur->next;
        cur->next=prev;
        prev=cur;
        cur=agla_node;
    }

    return prev;
} 

int main()
{   
    node* head=NULL;
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int d; cin>>d;
        insertAtTail(head,d);
    }
    print(head);
    head=reverseList(head);

    print(head);

    // HW: reverse recursively

    return 0;
}