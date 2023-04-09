#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* left,*right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* buildBst(node* root,int d)
{
    if(root==NULL)
    {
        root=new node(d);
        return root;
    }

    if(d<=root->data)
    {
        root->left=buildBst(root->left,d);
    }
    else
    {
        root->right=buildBst(root->right,d);
    }
    return root;
}

void inorder(node* root)
{
    if(root==NULL) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int smallestInBst(node* root)
{
    node* temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp->data;
}

int largestInBst(node* root)
{
    node* temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp->data;
}

node* search(node* root,int targetVal) // O(H) where H is height
{
    // BALANCED BST: O(H)=O(logN)
    // SKEWED BST: O(H)=O(N)
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==targetVal)
    {
        return root;
    }
    if(targetVal<=root->data)
    {
        return search(root->left,targetVal);
    }
    else
    {
        return search(root->right,targetVal);
    }
}




int main()
{

    node* root=NULL;
    int d; cin>>d;
    while(d!=-1)
    {
        root=buildBst(root,d);
        cin>>d;
    }

    inorder(root);

    return 0;
}
