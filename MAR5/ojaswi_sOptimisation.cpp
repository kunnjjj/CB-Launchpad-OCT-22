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

node* buildTree(node* root,int d)
{
    if(root==NULL)
    {
        root=new node(d);
        return root;
    }
    if(d<root->data)
    {
        root->left=buildTree(root->left,d);
    }
    else
    {
        root->right=buildTree(root->right,d);
    }
    return root;
}

node* deleteNode(node* root,int target)
{
    if(root==NULL) 
    {
        return NULL;
    }
    if(root->data==target)
    {
        // DELETE KA LOGIC
        // case1: no children
        if(root->left==NULL && root->right==NULL)
        {
            delete(root);
            return NULL;
        }
        // case2: part1: left child
        else if(root->left!=NULL && root->right==NULL)
        {
            node* temp=root->left;
            delete(root);
            return temp;
        }
        //case2: part2: right child 
        else if(root->left==NULL && root->right!=NULL)
        {
            node* temp=root->right;
            delete(root);
            return temp;
        }
        // case3: both children are present
        else
        {
            // inorder successor
            node* temp=root->right;
            node* prev=root;
            while(temp->left!=NULL)
            {
                prev=temp;
                temp=temp->left;
            }
            // temp now will inorder successor
            swap(root->data,temp->data);
			if(prev!=root)
            prev->left=deleteNode(temp,target);
			if(prev==root)
			{
				prev->right=deleteNode(temp,target);
			}
            return root;

            // inorder predecessor
            // node* temp=root->left;
            // while(temp->right!=NULL)
            // {
            //     temp=temp->right;
            // }
            // swap(root->data,temp->data);
            // root->left=deleteNode(root->left,target);
            // return root;

        }
    }
    else if(target < root->data)
    {
        root->left=deleteNode(root->left,target);
        return root;
    }
    else
    {
        root->right=deleteNode(root->right,target);
        return root;
    }
}

void preOrder(node* root)
{
    if(root==NULL) return ;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}

void test_case()
{
    int n; cin>>n;
    node* root=NULL;
    for(int i=0;i<n;i++)
    {
        int d; cin>>d;
        root=buildTree(root,d);
    }
    int m; cin>>m;
    for(int i=0;i<m;i++)
    {
        int d; cin>>d;
        root=deleteNode(root,d);
    }
    preOrder(root);
    cout<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        test_case();
    }

    return 0;
}