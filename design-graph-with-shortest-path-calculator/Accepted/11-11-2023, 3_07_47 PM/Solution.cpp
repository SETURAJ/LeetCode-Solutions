// https://leetcode.com/problems/design-graph-with-shortest-path-calculator

class Graph {
public:
    vector<pair<int,int>>graph[100];
    Graph(int n, vector<vector<int>>& edges) {
        for(auto e:edges)
        {
            graph[e[0]].push_back(make_pair(e[1],e[2]));
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back(make_pair(edge[1],edge[2]));
    }
    
    int shortestPath(int node1, int node2) {
        int sz = 100;
        vector<int>dist(sz,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>>pq;
        pq.push(make_pair(node1,0));
        dist[node1]=0;
        while(!pq.empty())
        {
            int u = pq.top().first;
            pq.pop();
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
        if(dist[node2]== INT_MAX)
            dist[node2]=-1;
        return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */