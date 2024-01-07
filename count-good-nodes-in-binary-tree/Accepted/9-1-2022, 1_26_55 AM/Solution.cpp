// https://leetcode.com/problems/count-good-nodes-in-binary-tree

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
    int ans=0;
    
    void preorder(TreeNode* root,int max_v)
    {
        if(!root)
            return ;
        if(root->val>=max_v)
        {
            ans++;
            max_v=root->val;
        }
        preorder(root->left,max_v);
        preorder(root->right,max_v);
    }
    
    int goodNodes(TreeNode* root) {
        preorder(root,INT_MIN);
        return ans;    
    }
};