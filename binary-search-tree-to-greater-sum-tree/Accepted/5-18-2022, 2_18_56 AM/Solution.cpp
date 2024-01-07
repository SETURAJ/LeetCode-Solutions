// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree

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
    
    void revinorder(TreeNode* root,int &count)
    {
        if(root==NULL)
            return;
        revinorder(root->right,count);
        
        root->val+=count;
        count=root->val;
            
        revinorder(root->left,count);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int count=0;
        revinorder(root,count);
        return root;
    }
};