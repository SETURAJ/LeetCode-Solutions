// https://leetcode.com/problems/reachable-nodes-with-restrictions

class Solution {
public:
    void dfs(int node, vector<int>adj[],vector<int >&vis,unordered_map<int,int>&m) 
    { 
        if(m.find(node)!=m.end()) 
            return; 
        vis[node] = true; 
        for(auto it : adj[node]) 
        { 
            if(!vis[it]) 
                dfs(it,adj,vis,m); 
        } 
        return; 
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) 
    {  
        vector<int> adj[n]; 
        for(auto it : edges) 
        { 
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        } 
         
        vector<int> vis(n,false); 
        unordered_map<int,int> m; 
        for(auto it : restricted) 
            m[it]++; 
         
        dfs(0,adj,vis,m);
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i])
                res++;
        }
        return res;
    }
};