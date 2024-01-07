// https://leetcode.com/problems/minimum-absolute-difference-in-bst

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
    int res=INT_MAX;
    TreeNode* prev=NULL;
    void inorder(TreeNode *root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        if(prev)
        {
            res=min(res,abs(prev->val-root->val));
        }
        prev=root;
        inorder(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return res;
    }
};