// https://leetcode.com/problems/symmetric-tree

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
    
    bool check(TreeNode* p,TreeNode* q)
    {
        if(p==NULL || q==NULL)
            return p==q;
        if(p->val!=q->val)
            return false;
        if(check(p->left,q->right)&&check(p->right,q->left))
            return true;
        else
            return false;
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right)
            return true;
        if(!root->left || !root->right)
            return false;
        return check(root,root);
    }
};