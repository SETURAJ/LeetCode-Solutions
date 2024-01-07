// https://leetcode.com/problems/minimum-depth-of-binary-tree

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
    
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        if(root->left ==NULL && root->right==NULL)
            return 1;
        int lheight=root->left!=NULL?height(root->left):INT_MAX;
        int rheight=root->right!=NULL?height(root->right):INT_MAX;
        return 1+min(lheight,rheight);
    }
    
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return height(root);
    }
};