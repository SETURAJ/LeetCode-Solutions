// https://leetcode.com/problems/balanced-binary-tree

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
    
    int check(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int lheight=0;
        int rheight=0;
        lheight=check(root->left);
        rheight=check(root->right);
        if(abs(lheight-rheight)>1)
            return 0;
        else if(lheight>rheight)
            return lheight+1;
        else
            return rheight+1;
        
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        if(check(root))
            return true;
        return false;
    }
};