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
    int ans;
    // int height(TreeNode* root)
    // {
    //     if(root==NULL)
    //     {
    //         return -1;
    //     }
    //     int leftKiHeight=height(root->left);
    //     int rightKiHeight=height(root->right);
    //     ans=max(ans,2 + leftKiHeight+rightKiHeight);
    //     return 1+max(leftKiHeight,rightKiHeight);
    // }

    pair<int,int> helper(TreeNode* root)
    {
        // {heightOfroot,subtree of root mein max diameter kitna hai}
        if(root==NULL)
        {
            pair<int,int> p;
            p.first=-1;
            p.second=0;
            return p;
        }
        pair<int,int> leftSubtree=helper(root->left);
        pair<int,int> rightSubtree=helper(root->right);
        pair<int,int> me;
        me.first= 1 + max(leftSubtree.first,rightSubtree.first);
        me.second=max({
            leftSubtree.second,
            rightSubtree.second,
            2 + leftSubtree.first + rightSubtree.first
        });
        return me;
    }

    // void preorderTraversal(TreeNode* root) // calculated 
    // {
    //     if(root==NULL) 
    //     {
    //         return ;
    //     }

    //     int leftKiHeight=height(root->left);
    //     int rightKiHeight=height(root->right);
    //     ans=max(ans,
    //     2 + leftKiHeight  + rightKiHeight // max len of path that goes through this node in its subtree
    //     );
    //     preorderTraversal(root->left);
    //     preorderTraversal(root->right);
    // }

    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).second;
    }
};

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
    int ans;
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return -1;
        }
        int leftKiHeight=height(root->left);
        int rightKiHeight=height(root->right);
        ans=max(ans,2 + leftKiHeight+rightKiHeight);
        return 1+max(leftKiHeight,rightKiHeight);
    }

    
    // void preorderTraversal(TreeNode* root) // calculated 
    // {
    //     if(root==NULL) 
    //     {
    //         return ;
    //     }

    //     int leftKiHeight=height(root->left);
    //     int rightKiHeight=height(root->right);
    //     ans=max(ans,
    //     2 + leftKiHeight  + rightKiHeight // max len of path that goes through this node in its subtree
    //     );
    //     preorderTraversal(root->left);
    //     preorderTraversal(root->right);
    // }

    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        // preorderTraversal(root);
        height(root);
        return ans;
    }
};