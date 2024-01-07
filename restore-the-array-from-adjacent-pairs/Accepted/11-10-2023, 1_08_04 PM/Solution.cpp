// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>umap;
        for(auto e:adjacentPairs)
        {
            umap[e[0]].push_back(e[1]);
            umap[e[1]].push_back(e[0]);
        }
        int root = 0;
        for(auto g:umap)
        {
            if(g.second.size()==1)
            {
                root = g.first;
                break;
            }
        }
        int curr = root;
        vector<int>res;
        res.push_back(root);
        int prev = INT_MAX;
        
        while(res.size() < umap.size())
        {
            for(auto n:umap[curr])
            {
                if(n!=prev)
                {
                    res.push_back(n);
                    prev = curr;
                    curr = n;
                    break;
                }
            }
        }
        return res;
    }
};