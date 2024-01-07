// https://leetcode.com/problems/binary-tree-paths

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
    vector<string>ans;
    
    void solve(TreeNode* root,string s)
    {
        if(root==NULL)
            return;
        s+=to_string(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(s);
            return;
        }
        s+="->";
        solve(root->left,s);
        solve(root->right,s);
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        string path;
        solve(root,path);
        return ans;
    }
};