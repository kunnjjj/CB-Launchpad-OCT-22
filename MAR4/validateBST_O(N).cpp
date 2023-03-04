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
 
class nodeHelper
{
    public:
    bool isBst;
    long long maxInSubtree;
    long long minInSubtree;
    nodeHelper()
    {
        isBst=true;
        maxInSubtree=(long long)-1e12;
        minInSubtree=(long long)1e12;
    }
};

class Solution {
public:

    nodeHelper giveNodeHelper(TreeNode* root)
    {
        nodeHelper myHelper;
        if(root==NULL)
        {
            return myHelper;
        }
        nodeHelper leftNodeHelper=giveNodeHelper(root->left);
        nodeHelper rightNodeHelper=giveNodeHelper(root->right);

        myHelper.isBst=leftNodeHelper.isBst &&
                        rightNodeHelper.isBst &&
                        leftNodeHelper.maxInSubtree < root->val &&
                        root->val < rightNodeHelper.minInSubtree;

        myHelper.maxInSubtree=max({
            leftNodeHelper.maxInSubtree,
            rightNodeHelper.maxInSubtree,
            (long long)root->val
        });
        myHelper.minInSubtree=min({
            leftNodeHelper.minInSubtree,
            rightNodeHelper.minInSubtree,
            (long long)root->val
        });
        return myHelper;
    }



    bool isValidBST(TreeNode* root) {
        return giveNodeHelper(root).isBst;
    }
};