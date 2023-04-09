#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void invertBinaryTree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    swap(root->left, root->right);
    invertBinaryTree(root->left);
    invertBinaryTree(root->right);
}

void levelOrderTraversal(node *root);

int height(node* root)
{
    if(root==NULL) return 0;

    int rightKiHeight=height(root->right);
    int leftKiHeight=height(root->left);    
    return 1 + max(rightKiHeight,leftKiHeight);
}

int main()
{
    node *root = NULL;
    root = buildTree();

    // preOrder(root);
    // cout<<endl;

    // invertBinaryTree(root);

    preOrder(root);
    cout << endl;

    levelOrderTraversal(root);

    return 0;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty()) // TODO
    {
        node *frontNode = q.front();
        cout << frontNode->data << " ";
        q.pop();
        if (frontNode->left != NULL)
            q.push(frontNode->left);
        if (frontNode->right != NULL)
            q.push(frontNode->right);
    }
}

void levelOrderWithNewLine(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int sizeOfCurLevel = q.size();
        for (int i = 1; i <= sizeOfCurLevel; i++)
        {
            node *frontNode = q.front();
            cout << frontNode->data << " ";
            q.pop();
            if (frontNode->left != NULL)
                q.push(frontNode->left);
            if (frontNode->right != NULL)
                q.push(frontNode->right);
        }
        cout << endl;
    }
}

void levelOrderWithNewLineMethod2(node *root)
{
    //
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while ((int)q.size() > 1)
    {
        node *frontNode = q.front();
        q.pop();
        if (frontNode == NULL)
        {
            q.push(NULL);
            cout << endl;
        }
        else
        {
            cout << frontNode->data << " ";
            if (frontNode->left != NULL)
                q.push(frontNode->left);
            if (frontNode->right != NULL)
                q.push(frontNode->right);
        }
    }
}




// node* a=new node(10);
// node* b=a;
// if(a==b)
// {
//     cout<<"they are equal"<<endl;
// }
// else
// {
//     cout<<"node"<<endl;
// }