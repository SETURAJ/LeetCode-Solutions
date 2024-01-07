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
    
    pair<int,int>find(TreeNode* node)
    {
        if(!node)
            return make_pair(0,0);
        auto l=find(node->left);
        auto r=find(node->right);
        int f2=l.second+r.second;
        int f1=max(f2,l.first+r.first+node->val);
        return make_pair(f2,f1);
    }
    
    int rob(TreeNode* root) 
    {
        if(!root)
            return 0;
        return find(root).second;
    }
};