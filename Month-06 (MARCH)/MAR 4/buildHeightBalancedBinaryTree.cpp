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


node* buildBalancedBSTFromSortedArray(int *A,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }

    int mid=(s+e)/2; // INTOVERFLOW WALE CASE MEIN s+(e-s)/2 , e-(e-s)/2;
    node* root=new node(A[mid]);
    root->left=buildBalancedBSTFromSortedArray(A,s,mid-1);
    root->right=buildBalancedBSTFromSortedArray(A,mid+1,e);
    return root;
}

void inorder(node* root)
{
    if(root==NULL) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    int A[]={2,3,4,5,10,12,14};
    int n=sizeof(A)/sizeof(int);

    node* root=buildBalancedBSTFromSortedArray(A,0,n-1);




    return 0;
}