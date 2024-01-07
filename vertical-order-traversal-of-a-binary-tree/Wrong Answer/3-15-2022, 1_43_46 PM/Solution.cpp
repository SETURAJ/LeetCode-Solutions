// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
            if(root==NULL)
                return res;
        queue<pair<TreeNode *,int>>q;
        map<int,vector<int>>m;
        q.push({root,0});
        while(!q.empty())
        {
            TreeNode *temp=q.front().first;
            int h=q.front().second;
            q.pop();
            m[h].push_back(temp->val);
            if(temp->left)
                q.push({temp->left,h-1});
            if(temp->right)
                q.push({temp->right,h+1});
        }
        for(auto x:m)
            res.push_back(x.second);
        return res;
    }
};