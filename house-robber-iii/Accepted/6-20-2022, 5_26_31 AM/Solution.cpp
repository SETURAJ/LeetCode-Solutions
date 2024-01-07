// https://leetcode.com/problems/house-robber-iii

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
    
    unordered_map<TreeNode*,int>dp;
    int find(TreeNode* root)
    {
        if(!root)
            return 0;
        if(dp.count(root))
            return dp[root];
        int ans_inc_root=root->val;
        if(root->left!=NULL)
            ans_inc_root+=find(root->left->left)+find(root->left->right);
        if(root->right!=NULL)
            ans_inc_root+=find(root->right->left)+find(root->right->right);
        int ans_exc_root=find(root->left)+find(root->right);
        int ans=max(ans_inc_root,ans_exc_root);
        dp[root]=ans;
        
        return ans;
        
    }
    
    int rob(TreeNode* root) 
    {
        if(!root)
            return 0;
        return find(root);
    }
};