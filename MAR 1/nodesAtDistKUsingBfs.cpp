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
    int maxSize;
    vector<TreeNode*> parentPointers;
    vector<int> dist;
    void getParents(TreeNode* root,TreeNode* parent)
    {
        if(root==NULL) return ;
        parentPointers[root->val]=parent;
        getParents(root->left,root);
        getParents(root->right,root);
    }

    vector<int> ans;
    int INF;
    void bfs(TreeNode* src,int k)
    {
        queue<TreeNode*> q;
        q.push(src);
        dist[src->val]=0;
        while(!q.empty())
        {
            TreeNode* frontNode=q.front();
            q.pop();
            // cout<<"frontNode->val: "<<frontNode->val<<endl;
            if(dist[frontNode->val]==k)
            {
                ans.push_back(frontNode->val);
            }

            TreeNode* parent=parentPointers[frontNode->val];
            if(frontNode->left!=NULL && dist[(frontNode->left)->val]==INF)
            {
                dist[(frontNode->left)->val]=1+ dist[frontNode->val];
                q.push(frontNode->left);
            }

            if(frontNode->right!=NULL && dist[(frontNode->right)->val]==INF)
            {
                dist[(frontNode->right)->val]=1+ dist[frontNode->val];
                q.push(frontNode->right);
            }
            if(parent!=NULL && dist[parent->val]==INF)
            {
                dist[parent->val]=1 + dist[frontNode->val];
                q.push(parent);
            }
        }       
    }

    vector<int> distanceK(TreeNode* root, TreeNode* src, int k) {
        maxSize=500;
        parentPointers=vector<TreeNode*> (501,NULL);
        getParents(root,NULL);
        INF=INT_MAX;
        dist=vector<int> (501,INF);

        bfs(src,k);
        return ans;     
    }
};