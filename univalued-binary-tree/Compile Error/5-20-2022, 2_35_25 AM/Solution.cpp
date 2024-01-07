// https://leetcode.com/problems/univalued-binary-tree

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
    
    bool dfs(TreeNode* root,int &cur)
    {
        if(root==NULL)
            return true;
        if(cur!=root->val)
            return false;
        dfs(root->left,cur);
        dfs(root->right,cur);
    }
    
    bool isUnivalTree(TreeNode* root) {
        int cur=root->val;
        return dfs(root,cur);
        //return curr==root->val?true:false;
    }
};