// https://leetcode.com/problems/count-complete-tree-nodes

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
    int res=0;

    void inorder(TreeNode *root)
    {
        if(!root)
            return;
        inorder(root->left);
        res++;
        inorder(root->right);
    }

    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        inorder(root);
        return res;
    }
};