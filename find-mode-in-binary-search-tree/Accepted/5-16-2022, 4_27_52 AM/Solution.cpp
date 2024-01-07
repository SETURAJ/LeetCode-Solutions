// https://leetcode.com/problems/find-mode-in-binary-search-tree

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
    
    void traverseBST(TreeNode* node)
    {
        if(node==NULL)
            return;
        traverseBST(node->left);
        umap[node->val]++;
        traverseBST(node->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        traverseBST(root);
        vector<int>res;
        int maxfreq=0;
        for(auto it=umap.begin();it!=umap.end();it++)
        {
            if(it->second>maxfreq)
                maxfreq=it->second;
        }
        for(auto it=umap.begin();it!=umap.end();it++)
        {
            if(it->second == maxfreq)
                res.push_back(it->first);
        }
        return res;
        
    }
};