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
        if(p==NULL && q==NULL)
            return true;
        if(p==NULL || q==NULL)
            return false;
        if(p->val !=q->val)
            return false;
        return check(p->left,q->right) && check(p->right,q->left);
        
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
            return true;
        return check(root->left,root->right);
    }
};