// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree

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
    int res=0;
    
public:
    
    void postorder(TreeNode* root,unordered_map<int,int>&umap)
    {
        if(!root)
        {
            return;
        }
        umap[root->val]++;
        if(!root->left && !root->right)
        {
            int count =0;
            for(auto i:umap)
            {
                if(i.second%2==1)
                    count++;
            }
            if(count<=1)
                res++;
        }
        postorder(root->left,umap);
        postorder(root->right,umap);
        umap[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>umap;
        postorder(root,umap);
        return res;
    }
};