/**
 * https://leetcode.com/problems/diameter-of-binary-tree/
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
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return -1;
        }
        return 1+max(height(root->left),height(root->right));
    }

    int ans;
    void preorderTraversal(TreeNode* root) // calculated 
    {
        if(root==NULL) 
        {
            return ;
        }

        int leftKiHeight=height(root->left);
        int rightKiHeight=height(root->right);
        ans=max(ans,
        2 + leftKiHeight  + rightKiHeight // max len of path that goes through this node in its subtree
        );
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        preorderTraversal(root);
        return ans;
    }
};