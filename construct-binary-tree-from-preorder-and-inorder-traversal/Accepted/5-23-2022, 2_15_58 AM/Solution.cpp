// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int& rootidx,int left, int right)
    {
        if(left>right)
            return NULL;
        int pivot=left;
        while(inorder[pivot]!=preorder[rootidx])
            pivot++;
        rootidx++;
        TreeNode* node=new TreeNode(inorder[pivot]);
        node->left=build(preorder,inorder,rootidx,left,pivot-1);
        node->right=build(preorder,inorder,rootidx,pivot+1,right);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootidx=0;
        return build(preorder,inorder,rootidx,0,inorder.size()-1);
    }
};