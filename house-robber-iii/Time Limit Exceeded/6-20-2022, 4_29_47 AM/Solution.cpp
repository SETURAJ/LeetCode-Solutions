// https://leetcode.com/problems/house-robber-iii

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
    int rob(TreeNode* root,bool canrob=true) 
    {
        if(!root)
            return 0;
        int dontrob=rob(root->left,true)+rob(root->right,true);
        int robbed=canrob? root->val+rob(root->left,false)+rob(root->right,false):-1;
        return max(dontrob,robbed);
    }
};