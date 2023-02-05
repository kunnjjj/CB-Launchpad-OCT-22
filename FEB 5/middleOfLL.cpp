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

node *insertAtTail(node *head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return head;
    }
    head->next = insertAtTail(head->next, d);
    return head;
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

node*  deleteAtPos(int pos,node* head) // assuming valid position 
{
    if(head==NULL) return head; // underflow case
    if(pos==1)
    {
        node* temp=head->next;
        delete(head);
        return temp;
    }
    head->next=deleteAtPos(pos-1,head->next);
    return head;
}

node* mid(node* head)
{
    if(head==NULL or head->next==NULL) return head;

    node* slow=head,*fast=head->next;
    while(fast!=NULL && fast->next!=NULL) //M1
    {
        //M2 (fast->next!=NULL && fast!=NULL) 
        fast=fast->next->next;
        slow=slow->next;
    }
    // M1 is better because it might happen that fast=NULL, which in M2 might create a 
    // runtime error as we would be checking fast->next!=NULL, where fast=NULL
    return slow;
}

int main()
{
    node *head = NULL;

    int d;
    cin >> d;
    while (d != -1)
    {
        head = insertAtTail(head, d);
        cin >> d;
    }
    // APPROACH 1: length -> length/2 tak traverse
    // APPROACH 2: fast and slow pointer
    node* middle=mid(head); 
    if(middle!=NULL)
    cout<<"mid->data: "<<middle->data<<"\n";

    return 0;
}