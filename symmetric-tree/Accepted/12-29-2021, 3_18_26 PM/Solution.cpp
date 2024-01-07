// https://leetcode.com/problems/symmetric-tree

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
    
    bool check(TreeNode* l,TreeNode* r)
    {
        if(!l && !r)
            return true;
        if(!l || !r)
            return false;
        if(l->val!=r->val)
            return false;
        if(!check(l->left,r->right))
            return false;
        if(!check(l->right,r->left))
            return false;
        
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right)
            return true;
        if(!root->left || !root->right)
            return false;
        return check(root->left,root->right);
    }
};