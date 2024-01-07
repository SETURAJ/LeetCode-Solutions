// https://leetcode.com/problems/all-elements-in-two-binary-search-trees

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
    vector<int>res;
    
    void inorder(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL || root2==NULL)
            return ;
        inorder(root1->left,root2->left);
        
        if(root1->val>root2->val)
        {
            res.push_back(root2->val);
            res.push_back(root1->val);
        }
        else
        {
            res.push_back(root1->val);
            res.push_back(root2->val);
        }
        
        inorder(root1->right,root2->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder(root1,root2);
        return res;
    }
};