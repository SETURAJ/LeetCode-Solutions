// https://leetcode.com/problems/path-sum-ii

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
    vector<vector<int>>res;
    vector<int>path;
    void preorder(TreeNode* root, int target)
    {
        if(root==NULL)
            return;
        target-=root->val;
        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            if(target==0)
                res.push_back(path);
        }
        else
        {
            preorder(root->left,target);
            preorder(root->right,target);
        }
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        preorder(root,targetSum);
        return res;
    }
};