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
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root->left == NULL && root->right==NULL)
            return true;
        if(root->left ==NULL)
            return true;
        if(root->right==NULL)
            return true;
        if(root->val <= root->left->val)
            return false;
        if(root->val >= root->right->val)
            return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};