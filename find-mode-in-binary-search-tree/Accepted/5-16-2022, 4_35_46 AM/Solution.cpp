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
    int maxcount=INT_MIN,curr=0;
    vector<int>res;
    TreeNode* prev=NULL;
    
    void traverseBST(TreeNode* node,bool flag)
    {
        if(node==NULL)
            return;
        traverseBST(node->left,flag);
        if(prev && prev->val == node->val)
            curr++;
        else
            curr=1;
        if(!flag)
            maxcount=max(maxcount,curr);
        else if(maxcount==curr)
            res.push_back(node->val);
        prev=node;
        traverseBST(node->right,flag);
    }
    
    vector<int> findMode(TreeNode* root) {
        if(!root)
            return res;
        traverseBST(root,false);
        prev=NULL;
        curr=0;
        traverseBST(root,true);
        return res;
        
    }
};