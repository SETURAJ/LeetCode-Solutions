// https://leetcode.com/problems/delete-node-in-a-bst

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
    
    TreeNode* find_succ(TreeNode* root)
    {
        TreeNode* curr=root;
        while(curr && curr->left!=NULL)
            curr=curr->left;
        return curr;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        if(key>root->val)
            root->right=deleteNode(root->right,key);
        else if(key<root->val)
            root->left=deleteNode(root->left,key);
        else
        {
            if(root->left==NULL && root->right==NULL)
                return NULL;
            else if(root->left==NULL)
            {
                TreeNode* temp=root->right;
                free(root);
                return temp;
            }
            else if(root->right==NULL)
            {
                TreeNode* temp=root->left;
                free(root);
                return temp;
            }
            TreeNode* temp=find_succ(root->right);
            root->val=temp->val;
            root->right=deleteNode(root->right,temp->val);
        }
        return root;
    }
};