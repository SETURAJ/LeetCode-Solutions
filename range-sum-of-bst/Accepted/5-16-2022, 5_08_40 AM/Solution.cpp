// https://leetcode.com/problems/range-sum-of-bst

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
    
    void inorder(TreeNode* root,int low,int high)
    {
        if(root==NULL)
            return;
        
        inorder(root->left,low,high);
        if(root->val>=low && root->val <=high)
            res+=root->val;
        inorder(root->right,low,high);
        
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root->val> high)
            inorder(root->left,low,high);
        else if(root->val <low)
            inorder(root->right,low,high);
        else
            inorder(root,low,high);
        return res;
    }
};