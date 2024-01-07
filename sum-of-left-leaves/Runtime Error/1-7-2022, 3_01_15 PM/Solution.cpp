// https://leetcode.com/problems/sum-of-left-leaves

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
    
    void solve(TreeNode* root)
    {
        if(!root)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            ans+=root->val;
            return;
        }
        solve(root->left);
        if(root->right->left)
            solve(root->right);
        return;
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
            return 0;
        if(!root)
            return 0;
        solve(root);
        
        return ans;
    }
};