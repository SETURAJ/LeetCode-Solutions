// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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
    
    unordered_map<int,int>umap;
    
    TreeNode* build(vector<int>&in,vector<int>&post,int left,int right,int& postidx)
    {
        if(left>right)
            return NULL;
        TreeNode* root=new TreeNode(post[postidx]);
        postidx--;
        int rootidx=umap[root->val];
        root->right=build(in,post,rootidx+1,right,postidx);
        root->left=build(in,post,left,rootidx-1,postidx);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
            umap[inorder[i]]=i;
        int n=inorder.size();
        int postidx=n-1;
        return build(inorder,postorder,0,n-1,postidx);
    }
};