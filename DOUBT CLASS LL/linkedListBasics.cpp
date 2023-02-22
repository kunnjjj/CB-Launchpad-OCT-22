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

void insertAtTail(node *&head, node *&tail, int d)
{
    if (head == NULL) // LL was empty
    {
        tail = new node(d);
        head = tail;
        return ;
    }

    node* nayiNode=new node(d);
    tail->next=nayiNode;
    tail=tail->next;
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



int main()
{

    node *head = NULL, *tail = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        insertAtTail(head, tail, d);
    }

    print(head);

    printRec(head);

    

    return 0;
}