// https://leetcode.com/problems/path-sum

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
    int sum=0;

    bool ispathsum(TreeNode* root,int targetSum)
    {
        if(root==NULL)
            return false;
        if(root->left==NULL && root->right==NULL && root->val==targetSum)
            return true;
        return ispathsum(root->left,targetSum-root->val) || ispathsum(root->right,targetSum-root->val);
    } 

    bool hasPathSum(TreeNode* root, int targetSum) {
        return ispathsum(root,targetSum);
    }
};