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
    int l,r=0;
    bool flag=true;
    int check(TreeNode* root,int l,int r)
    {
        if(root==NULL)
            return 0;
        l=check(root->left,l,r);
        r=check(root->right,l,r);
        if(abs(l-r)>1)
        {
            flag=false;
            return 0;
        }
        return 1+max(l,r);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
       check(root,l,r);
        return flag;
    }
};