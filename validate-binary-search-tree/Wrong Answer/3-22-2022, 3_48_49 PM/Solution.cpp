// https://leetcode.com/problems/validate-binary-search-tree

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
    
    bool isValid(TreeNode *root,int low,int high)
    {
        if(root==NULL)
            return true;
        if(root->val <= low || root->val >=high)
            return false;
        bool l,r;
        l=isValid(root->left,low,root->val);
        r=isValid(root->right,root->val,high);
        return l&&r;
            
    }
        
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        return isValid(root,INT_MIN,INT_MAX);
    }
};