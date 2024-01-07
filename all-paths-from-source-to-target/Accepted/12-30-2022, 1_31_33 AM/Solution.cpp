// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:

    void dfs(vector<vector<int>>& g,vector<vector<int>>&res,vector<int>&path, int curr)
    {
        path.push_back(curr);
        if(curr==g.size()-1)
            res.push_back(path);
        else for(auto it:g[curr])
        {
            dfs(g,res,path,it);
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>res;
        vector<int>path;
        dfs(graph,res,path,0);
        return res;
    }
};