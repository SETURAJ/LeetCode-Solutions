// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    
    int findsum(TreeNode *root,int &ans)
    {
        if(root==NULL)
            return 0;
        int left=max(0,findsum(root->left,ans));
        int right=max(0,findsum(root->right,ans));
        int val=root->val;
        ans=max(ans,left+right+val);
        return max(left,right) +val;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        findsum(root,ans);
        return ans;
    }
};