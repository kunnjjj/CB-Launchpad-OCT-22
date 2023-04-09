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

node* mergeTwoSortedLinkedList(node* head1, node* head2) {
        
        if(head1==NULL)
        {
            return head2;
        }
        if(head2==NULL)
        {
            return head1;
        }

        node* mergedList=NULL;
        if(head1->data < head2->data)
        {
            mergedList=head1;
            mergedList->next=mergeTwoSortedLinkedList(head1->next,head2);
        }
        else
        {
            mergedList=head2;
            mergedList->next=mergeTwoSortedLinkedList(head1,head2->next);
        }
        return mergedList;
    }

node* mergeSort(node* head)
{
    if(head==NULL or head->next==NULL) return head;
    node* middle=mid(head);
    node* head2=middle->next;
    middle->next=NULL;
    head=mergeSort(head);
    head2=mergeSort(head2);
    node* mergedList=mergeTwoSortedLinkedList(head,head2);
    return mergedList;
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


    head=mergeSort(head);
    print(head);
    

    return 0;
}