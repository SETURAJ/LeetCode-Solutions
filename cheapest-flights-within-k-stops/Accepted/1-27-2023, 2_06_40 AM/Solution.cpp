// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,int>>q;
        vector<vector<pair<int,int>>>adj(n);
        for(auto f:flights)
        {
            adj[f[0]].push_back({f[1],f[2]});
        }
        q.push({src,0});
        vector<int>dist(n,INT_MAX);
        int stops=0;
        while(!q.empty() && stops<=k)
        {
            int sz=q.size();
            while(sz--)
            {
                auto [curr,cost]=q.front();
                q.pop();
                for(auto& [nd,cs] : adj[curr])
                {
                    if(cs+cost<=dist[nd])
                    {
                        dist[nd]=cs+cost;
                        q.push({nd,dist[nd]});
                    }
                }
            }
            stops++;
        }
        if(dist[dst]==INT_MAX)
            return -1;
        return dist[dst];
    }
};