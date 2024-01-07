// https://leetcode.com/problems/balance-a-binary-search-tree

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
    
    vector<int>tree;
    
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        tree.push_back(root->val);
        inorder(root->right);
    }
    
    
    TreeNode* createbst(int start,int end)
    {
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode* new_node=new TreeNode(tree[mid]);
        new_node->left=createbst(start,mid-1);
        new_node->right=createbst(mid+1,end);
        return new_node;
    }
        
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int n=tree.size();
        return createbst(0,n-1);
        
    }
};