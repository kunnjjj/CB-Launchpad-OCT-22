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

void insertAtHead(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        tail = head;
        return;
    }
    node *nayiNode = new node(data);
    nayiNode->next = head;
    head = nayiNode;
}

void insertAtTail(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        insertAtHead(head, tail, data);
        return;
    }
    tail->next = new node(data);
    tail = tail->next;
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printRecursive(node *head)
{
    if (head == NULL)
    {
        cout<<endl;
        return;
    }
    cout << head->data << " ";
    printRecursive(head->next);
}

int length(node *head)
{
    node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int lengthRecursive(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return 1 + lengthRecursive(head->next);
}

void insertAtPos(node *&head, node *&tail, int data, int pos)
{
    if (pos == 1 or head == NULL)
    {
        insertAtHead(head, tail, data);
        return;
    }
    node *temp = head;
    for (int i = 1; i <= pos - 2; i++)
    {

        temp = temp->next;
        if (temp == NULL)
        {
            insertAtTail(head, tail, data);
            return;
        }
    }

    node *nayiNode = new node(data);
    nayiNode->next = temp->next;
    temp->next = nayiNode;
}

void operator<<(ostream& o,node*& head)
{
    printRecursive(head);
}

void deleteAtHead(node*& head,node*& tail)
{
    if(head==NULL) 
    {
        return ;
    } 

    if(head->next==NULL)
    {
        delete(head);
        head=NULL;
        tail=NULL;
        return ;
    }

    node* temp=head;
    head=head->next;
    delete(temp);
}


void deleteAtTail(node* head,node*& tail)
{
    if(head==NULL) 
    {
        return ;
    } 

    if(head->next==NULL)
    {
        delete(head);
        head=NULL;
        tail=NULL;
        return ;
    }
    node* prev=head;
    node* temp=head->next;
    while(temp!=tail)
    {
        prev=prev->next;
        temp=temp->next;
    }
    tail=prev;
    prev->next=NULL;
    delete(temp);
}

void deleteCompleteList(node*& head,node*& tail)
{
    while(head!=NULL)
    {
        deleteAtHead(head,tail);
    }
}



int main()
{
    node *head = NULL;
    node *tail = NULL;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        insertAtTail(head, tail, d);
    }

    print(head);

    insertAtPos(head, tail, 10, 3);

    printRecursive(head);
    insertAtPos(head, tail, 9, 1);
    printRecursive(head);
    insertAtPos(head, tail, 9, 200);
    printRecursive(head);

    cout<<"using operator overloading: "<<endl;
    cout<<head;

    deleteCompleteList(head,tail);
    cout<<"after deletion: "<<endl;
    cout<<head;

    // HW: delete at position




    return 0;
}