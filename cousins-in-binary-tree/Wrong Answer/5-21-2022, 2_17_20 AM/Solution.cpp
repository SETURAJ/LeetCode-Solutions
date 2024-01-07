// https://leetcode.com/problems/cousins-in-binary-tree

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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val ==x || root->val ==y)
            return false;
        queue<pair<TreeNode* , int>>q;
        q.push({root,0});
        int h=0,a=0,b=0;
        while(!q.empty())
        {
            
            int len=q.size();
            h++;
            for(int i=0;i<len;i++)
            {
                TreeNode* node=q.front().first;
                int s=q.front().second;
                q.pop();
                if(node->val==x)
                    a=s;
                else if(node->val==y)
                    b=s;
                if(node->left)
                    q.push({node->left,h});
                if(node->right)
                    q.push({node->right,h});
                    
            }
        }
        return a==b;
    }
};