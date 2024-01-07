// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
        int lheight=0;
        int rheight=0;
        if(root==NULL)
            return 0;
        lheight=height(root->left);
        rheight=height(root->right);
        if(lheight)
            return lheight+1;
        else
            return rheight+1;
    }
    
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return height(root)+1;
    }
};