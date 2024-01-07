// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    const int inf = 1e9;
    vector<int>dijkstra(vector<pair<int,int>>graph[],int start,int V)
    {
        vector<int>dist(V+1,inf);
        vector<bool>vis(V+1,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        pq.push(make_pair(start,0));
        dist[start]=0;
        while(!pq.empty())
        {
            int u=pq.top().first;
            pq.pop();
            if(vis[u])continue;
            vis[u]=true;
            for(int i=0;i<graph[u].size();i++)
            {
                int v=graph[u][i].first;
                int w=graph[u][i].second;
                if(dist[v]>dist[u]+w)
                {
                    dist[v]=dist[u]+w;
                    pq.push(make_pair(v,dist[v]));
                }
            }
        }
        return dist;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>graph[n+1];
        for(const auto& edge:times)
        {
            graph[edge[0]].emplace_back(edge[1],edge[2]);
        }
        vector<int>dist=dijkstra(graph,k,n);
        int ans=*max_element(dist.begin()+1,dist.end());
        return ans==inf?-1:ans;
    }
};