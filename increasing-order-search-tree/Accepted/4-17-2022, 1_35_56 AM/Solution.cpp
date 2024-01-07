// https://leetcode.com/problems/increasing-order-search-tree

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
    TreeNode *ret=NULL;
    TreeNode* pre=NULL;
    
    TreeNode* increasingBST(TreeNode* root) {
        solve(root);
        return ret;
    }
    void solve(TreeNode* root)
    {
        if(root==NULL)
            return ;
        solve(root->left);
        if(pre)
            pre->right=root;
        else
            ret=root;
        root->left=NULL;
        pre=root;
        solve(root->right);
    }
    
    
};