/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* A1,*A2;
    TreeNode* prev,*cur;
    // TAKE GOOD NAMES OF VARIABLES AND FUNCTIONS IN INTERVIEW

    void findNodes(TreeNode* root)
    {
        if(root==NULL) return ;

        findNodes(root->left); // prev would have been updated as we are first making call on left subtree
        cur=root;
        if(prev!=NULL && prev->val > cur->val) // dikkat case
        {
            if(A1==NULL)
            {
                A1=prev;
                A2=cur;
            }
            else
            {
                A2=cur;
            }
        }
        prev=cur;
        findNodes(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        A1=NULL,A2=NULL;
        prev=NULL,cur=NULL;
        findNodes(root);
        swap(A1->val,A2->val);

    }
};