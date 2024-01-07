// https://leetcode.com/problems/n-ary-tree-level-order-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        vector<vector<int>>res;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>cur;
            for(int i=0;i<size;i++)
            {
                Node* tmp=q.front();
                q.pop();
                cur.push_back(tmp->val);
                for(auto n:tmp->children)
                    q.push(n);
            }
            res.push_back(cur);
        }
        return res;
    }
};