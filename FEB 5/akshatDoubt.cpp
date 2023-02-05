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

class Pair
{
public:
    node *head;
    node *tail;
    Pair(node *head1, node *tail1)
    {
        head = head1;
        tail = tail1;
    }
};

void insertAtTail(node*& head,node*& tail,int d)
{
    if(head==NULL)
    {
        head=new node(d);
        tail=head;
        return ;
    }
    tail->next=new node(d); 
    tail=tail->next;
} 

void operator<<(ostream& o,node*& head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Pair reverse(node* head)
{
    node* nayiTail=head;
    node* prev=NULL,* cur=head;
    while(cur!=NULL)
    {
        node* agle=cur->next;
        cur->next=prev;
        prev=cur;
        cur=agle;
    }
    node* nayaHead=prev;
    Pair P(nayaHead,nayiTail);
    return P;
}

node* reverseEvenParts(node* head)
{
    if(head==NULL or head->next==NULL)
    {
        return head;
    }
    if(head->data%2==1)
    {
        head->next=reverseEvenParts(head->next);
        return head;
    }
    node* temp=head;
    while(1)
    {
        if(temp->next==NULL or temp->next->data%2==1)
        {
            break;
        }
        temp=temp->next;
    }

    node* aageKiList=reverseEvenParts(temp->next);
    temp->next=NULL;
    Pair P=reverse(head);
    node* nayaHead=P.head,*nayiTail=P.tail;
    nayiTail->next=aageKiList;
    return nayaHead; 
}

int main()
{
    node* head=NULL,*tail=NULL;
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int d; cin>>d;
        insertAtTail(head,tail,d);
    }
    // cout<<head;
    head=reverseEvenParts(head);
    cout<<head;
    return 0;
}