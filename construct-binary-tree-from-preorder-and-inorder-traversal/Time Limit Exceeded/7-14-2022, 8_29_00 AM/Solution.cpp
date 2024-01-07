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
    int preIndex=0;
    
    TreeNode* getTree(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>m,int is,int ie){
        if(is>ie)
            return NULL;
        int p=m[preorder[preIndex]];
        TreeNode *root=new TreeNode(inorder[p]);
        preIndex++;
        root->left=getTree(preorder,inorder,m,is,p-1);
        root->right=getTree(preorder,inorder,m,p+1,ie);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>m;
        int n=inorder.size();
        for(int i=0;i<n;i++)
            m[inorder[i]]=i;
        return getTree(preorder,inorder,m,0,n-1);
    }
};