// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<int>dp[n+1];
        for(auto e:edges)
        {
            dp[e[0]].push_back(e[1]);
            dp[e[1]].push_back(e[0]);
        }
        vector<bool>vis(n+1,false);
        queue<int>q;
        q.push(source);
        vis[source]=true;
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            if(destination==temp)
                return true;
            for(auto it:dp[temp])
            {
                if(vis[it]==false)
                {
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
        return false;
        
    }
};