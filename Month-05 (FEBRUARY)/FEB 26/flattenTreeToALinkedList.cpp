/**
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 * 
 *
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
    pair<TreeNode*,TreeNode*> modifyTree(TreeNode* root)
    {
        if(root==NULL) return {NULL,NULL};
        if(root->left==NULL && root->right==NULL) return {root,root};
        if(root->left==NULL && root->right!=NULL)
        {
            pair<TreeNode*,TreeNode*> RAns=modifyTree(root->right);
            root->right=RAns.first;
            return {root,RAns.second};
        }
        if(root->left!=NULL && root->right==NULL)
        {
            pair<TreeNode*,TreeNode*> Lans=modifyTree(root->left);
            root->right=Lans.first;
            root->left=NULL;
            return {root,Lans.second};
        }
        pair<TreeNode*,TreeNode*> Lans=modifyTree(root->left);
        pair<TreeNode*,TreeNode*> RAns=modifyTree(root->right);
        root->right=Lans.first;
        (Lans.second)->right=RAns.first;
        root->left=NULL;
        return {root,RAns.second};
    }
    void flatten(TreeNode* root) {
        modifyTree(root);
    }
};