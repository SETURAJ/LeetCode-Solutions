// https://leetcode.com/problems/add-one-row-to-tree

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

    TreeNode* solve(TreeNode* root,int val,int depth,int curr)
    {
        if(root==NULL)
            return NULL;
        if(curr==depth-1)
        {
            TreeNode* l=new TreeNode(val);
            TreeNode* r=new TreeNode(val);
            l->left=root->left;
            r->right=root->right;
            root->left=l;
            root->right=r;
            return root;
        }
        else
        {
            solve(root->left,val,depth,curr+1);
            solve(root->right,val,depth,curr+1);
            return root;
        }
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* newnode=new TreeNode(val);
            newnode->left=root;
            return newnode;
        }
        return solve(root,val,depth,1);
    }
};