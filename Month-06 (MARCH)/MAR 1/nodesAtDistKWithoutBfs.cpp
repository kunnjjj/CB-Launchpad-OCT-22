/**
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
    vector<int> ans;

    void findInSubtree(TreeNode* root,int k)
    {
        if(root==NULL or k<0) return ;
        if(k==0) 
        {
            ans.push_back(root->val);
            return ;
        }
        findInSubtree(root->left,k-1);
        findInSubtree(root->right,k-1);
    }

    int distFromSrc(TreeNode* root,TreeNode* src,int k)
    {
        if(root==NULL) return -1; // -1 denotes src was not present in this substree
        if(root==src) 
        {
            findInSubtree(root,k);
            return 0;
        }
        int leftDist=distFromSrc(root->left,src,k);
        if(leftDist!=-1)
        {
            if(leftDist+1==k)
            {
                ans.push_back(root->val);
            }
            findInSubtree(root->right,k-leftDist-2);
            return 1 + leftDist;
        }
        int rightDist=distFromSrc(root->right,src,k);
        if(rightDist!=-1)
        {
            if(rightDist+1==k)
            {
                ans.push_back(root->val);
            }
            findInSubtree(root->left,k-rightDist-2);
            return 1 + rightDist;
        }   
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* src, int k) {
        distFromSrc(root,src,k);
        return ans;
    }
};