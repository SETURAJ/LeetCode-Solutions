// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return root;
        else if((p->val == root->val || q->val==root->val)||(root->val>p->val && root->val <q->val)||(root->val>q->val && root->val <p->val))
            return root;
        else if(root->val >(max(p->val,q->val)))
            return lowestCommonAncestor(root->left,p,q);
        else 
            return lowestCommonAncestor(root->right,p,q);
    }
};