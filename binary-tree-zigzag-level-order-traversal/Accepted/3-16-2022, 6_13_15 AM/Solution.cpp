// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)
            return res;
        queue<TreeNode *>q;
        q.push(root);
        int count=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>vec;
            for(int i=0;i<n;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                
                vec.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            if(count%2==0)
                res.push_back(vec);
            else
            {
                reverse(vec.begin(),vec.end());
                res.push_back(vec);
            }
            count++;
        }
        return res;
    }
};