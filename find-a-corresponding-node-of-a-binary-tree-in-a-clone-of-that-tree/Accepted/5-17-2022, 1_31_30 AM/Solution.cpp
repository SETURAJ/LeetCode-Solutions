// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

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
    
    TreeNode* res=new TreeNode();
    void inorder(TreeNode* root1,TreeNode* root2, TreeNode* target)
    {
        if(root1==NULL || root2==NULL)
            return;
        inorder(root1->left,root2->left,target);
        if(root1==target)
            res=root2;
        inorder(root1->right,root2->right,target);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        inorder(original,cloned,target);
        return res;
    }
};