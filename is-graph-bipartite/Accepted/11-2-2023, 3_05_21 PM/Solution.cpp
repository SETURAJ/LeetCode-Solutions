// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(auto x:graph[i])
                adj[i].push_back(x);
        }
        
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                queue<pair<int,int>>q;
                q.push({i,0});
                
                color[i]=0;
                while(!q.empty())
                {
                    pair<int,int> p = q.front();
                    int a = p.first;
                    int c = p.second;
                    q.pop();
                    for(auto x: adj[a])
                    {
                        if(color[x]==c)
                            return false;
                        else if(color[x]==-1)
                        {
                            if(c==0)
                                color[x]=1;
                            else
                                color[x]=0;
                            q.push({x,color[x]});
                        }
                    }
                }
            }
        }
        return true;
    }
};