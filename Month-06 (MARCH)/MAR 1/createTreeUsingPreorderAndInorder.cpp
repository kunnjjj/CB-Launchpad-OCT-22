#include<iostream>
#include<vector>
using namespace std;

class node
{
    public:
    int data;
    node* left,*right;
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

int idx=0;
node* buildTreeUsingPreorderInorder(vector<int> &inorder,vector<int> &preorder,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int rootKaData=preorder[idx];
    node* root=new node(rootKaData);
    int mila=-1;
    for(int i=s;i<=e;i++)
    {
        if(rootKaData==inorder[i])
        {
            mila=i;
            break;
        }
    }
    idx++;
    root->left=buildTreeUsingPreorderInorder(inorder,preorder,s,mila-1);
    root->right=buildTreeUsingPreorderInorder(inorder,preorder,mila+1,e);
    return root;
}

int main()
{
    int n; cin>>n;
    vector<int> preorder(n);
    for(int i=0;i<n;i++) cin>>preorder[i];

    int m; cin>>m;
    vector<int> inorder(m);
    for(int i=0;i<m;i++) cin>>inorder[i];

    node* root=buildTreeUsingPreorderInorder(inorder,preorder,0,n-1);



    return 0;
}