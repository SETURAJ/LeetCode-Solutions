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
    
    int height(TreeNode* root,int m)
    {
        if(root==NULL)
            return 0;
        int lheight=m;
        int rheight=m;
        lheight=height(root->left,min(lheight,rheight));
        rheight=height(root->right,min(lheight,rheight));
        return 1+min(lheight,rheight);
    }
    
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return height(root,1);
    }
};