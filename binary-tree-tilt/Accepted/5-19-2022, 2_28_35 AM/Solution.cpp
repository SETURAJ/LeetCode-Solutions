// https://leetcode.com/problems/binary-tree-tilt

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
    int tiltsum=0;
    
    int postorder(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int leftsum=postorder(root->left);
        int rightsum=postorder(root->right);
        tiltsum+=abs(leftsum-rightsum);
        return leftsum+rightsum+root->val;
    }
    
    int findTilt(TreeNode* root) {
        postorder(root);
        return tiltsum;
    }
    
    
};