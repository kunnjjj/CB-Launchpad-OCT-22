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

    print(head);
    deleteAtPos(3,head);
    print(head);

    return 0;
}