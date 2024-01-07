// https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
    int ans;
    void recurse(TreeNode* root,int ans)
    {
        if(root==NULL )
            return;
        recurse(root->left,ans);
        ans--;
        if(ans==0)
        {
            ans=root->val;
        }
        recurse(root->right,ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        ans=k;
        recurse(root,ans);
        return ans;
    }
};