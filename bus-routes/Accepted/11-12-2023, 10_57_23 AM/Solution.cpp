// https://leetcode.com/problems/bus-routes

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;
        unordered_map<int,vector<int>>graph;
        
        for(int i=0;i<routes.size();i++)
        {
            for(auto r:routes[i])
                graph[r].push_back(i);
        }
        
        queue<int>q;
        q.push(source);
        vector<bool> visited(routes.size(),false);
        int res = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int stop = q.front();
                q.pop();
                if(stop == target)
                    return res;
                for(auto st: graph[stop])
                {
                    if(visited[st])
                        continue;
                    visited[st] = true;
                    for(int r: routes[st])
                        q.push(r);
                }
            }
            res++;
        }
        
        return -1;
        
    }
};