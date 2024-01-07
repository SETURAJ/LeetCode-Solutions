// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        unsigned long long int ans=0;
        queue<pair<TreeNode*,unsigned long long int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            unsigned long long int n=q.size();
            unsigned long long int curmin=q.front().second;
            unsigned long long int leftmost,rightmost;
            for(unsigned long long int i=0;i<n;i++)
            {
                unsigned long long int cur_id=q.front().second - curmin;
                TreeNode *temp=q.front().first;
                q.pop();
                if(i==0)
                    leftmost=cur_id;
                if(i==n-1)
                    rightmost=cur_id;
                if(temp->left)
                    q.push({temp->left,cur_id*2+1});
                if(temp->right)
                    q.push({temp->right,cur_id*2+2});
            }
            ans=max(ans,rightmost-leftmost+1);
        }
        return ans;
    }
};