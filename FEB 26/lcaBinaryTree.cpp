/**
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)  
        {
            return NULL;
        }
        if(root==p) return root;
        if(root==q) return root;

        TreeNode* leftMeinMila=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightMeinMila=lowestCommonAncestor(root->right,p,q);

        if(leftMeinMila!=NULL && rightMeinMila!=NULL) return root;
        if(leftMeinMila!=NULL) return leftMeinMila;
        if(rightMeinMila!=NULL) return rightMeinMila;

        return NULL;

    }
};