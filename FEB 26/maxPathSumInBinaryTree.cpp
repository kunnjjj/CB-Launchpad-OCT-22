/**
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
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
#define node TreeNode
class Solution {
public:
        //best_sum(root) -> best_path_in_subtree
        
        int best_sum(int &ans,TreeNode* root)
        {
            if(root==NULL) return 0;
            
            int left_best=best_sum(ans,root->left);
            int right_best=best_sum(ans,root->right);
            int me=root->val;
            ans=max({ans,
                     me,               //best can be only me 
                     left_best +me,     // using left and me
                     right_best + me,    // using right and me
                     left_best+right_best+me}); //using both
            return max({me,left_best+me,right_best+me});
        }


    int maxPathSum(TreeNode* root) {
        int ans=-1e9;
          best_sum(ans,root);
        return ans;
    }
};