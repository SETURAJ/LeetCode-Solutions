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
    int l=0,r=0;
    bool flag=true;
    int check(TreeNode* root,int l,int r)
    {
        if(root==NULL)
            return 0;
        l=check(root->left,l,r);
        r=check(root->right,l,r);
        if(abs(l-r)>1)
            flag=false;
        if(l>r)
            return l+1;
        else
            return r+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        check(root,l,r);
        return true;
    }
};