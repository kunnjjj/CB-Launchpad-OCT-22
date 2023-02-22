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

node* reverse(node* head) // 
{
    node* cur=head, *prev=NULL;
    while(cur!=NULL) // TO-DO
    {
        node* aage=cur->next;
        cur->next=prev;
        prev=cur;
        cur=aage;
    }
    return prev;
}



void print(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ----> ";
        temp=temp->next;
    }
    cout<<endl;
}

void printRec(node* head)
{
    if(head==NULL)
    {
        cout<<endl;
        return ;
    }
    cout<<head->data<<" ---> ";
    printRec(head->next);
}


node* buildList(node* head,int d) // without reference
{
    if(head==NULL)
    {
        head=new node(d);
        return head;
    }
    head->next=buildList(head->next,d);
}   

int lengthRec(node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    return 1 + lengthRec(head->next);
}

int length(node* head)
{
    node* temp=head;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

node* middle(node* head)
{
    if(head==NULL) return NULL;
    node* slow=head,*fast=head->next;
    // while(fast!=NULL && fast->next!=NULL) // m2
    // {
    // }
    while(1)
    {
        if(fast==NULL || fast->next==NULL)
        {
            break;
        } // M1
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}



int main()
{

    node *head = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        head=buildList(head,d);
    }

    printRec(head);

    head=reverse(head);

    printRec(head);

    cout<<"middle: "<<(middle(head)->data)<<"\n";

    return 0;
}