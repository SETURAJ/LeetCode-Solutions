// https://leetcode.com/problems/invert-binary-tree

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
    
    TreeNode* invert(TreeNode* root)
    {
        if(root==NULL)
            return NULL;
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        if(root->left)
            invert(root->left);
        if(root->right)
            invert(root->right);
        return root;
    }
    
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        return invert(root);
    }
};