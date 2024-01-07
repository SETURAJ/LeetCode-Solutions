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
        if(!root)
            return 0;
        long long int ans = 0;
        queue<pair<TreeNode*, long long int>> q;
        q.push({root,0});
        while(!q.empty()){
            long long int size = q.size();
            long long int mmin = q.front().second;    
            long long int last;
            for(int i=0; i<size; i++){
                int cur_id = q.front().second-mmin;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==size-1)
                    last = cur_id;
                if(node->left)
                    q.push({node->left, cur_id*2});
                if(node->right)
                    q.push({node->right, cur_id*2+1});
            }
            ans = max(ans, last+1);
        }
        return ans;
    }
};