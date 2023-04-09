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
    long long maxInSubtree(TreeNode* root)
    {
        if(root==NULL)
        {
            return (long long)-1e12;
        }
        return max({
            (long long)root->val,
            maxInSubtree(root->left),
            maxInSubtree(root->right)
        });
    }
    long long minInSubtree(TreeNode* root)
    {
        if(root==NULL)
        {
            return (long long)1e12;
        }
        return min({
            (long long)root->val,
            minInSubtree(root->left),
            minInSubtree(root->right)
        });
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        // // M1
        // bool statement1= maxInSubtree(root->left) < (root->data);
        // bool statement2= root->data < minInSubtree(root->right);
        // bool statement3= isValidBST(root->left);
        // bool statement4= isValidBST(root->right);
        // return statement1 && statement2 && statement3 && statement4;

        // M2
        return  maxInSubtree(root->left) < (root->val) && 
                root->val < minInSubtree(root->right)  && 
                isValidBST(root->left) && 
                isValidBST(root->right);
    }
    // M2 is more efficient

};