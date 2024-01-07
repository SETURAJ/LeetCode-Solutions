// https://leetcode.com/problems/number-of-provinces

class Solution {
public:

    void bfs(int node,vector<vector<int>>&isConnected,vector<bool>&visited)
    {
        queue<int>q;
        q.push(node);
        visited[node]=true;
        while(!q.empty())
        {
            node = q.front();
            q.pop();

            for(int i=0;i<isConnected.size();i++)
            {
                if(isConnected[node][i] && !visited[i])
                {
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int res=0;
        int n=isConnected.size();
        vector<bool>visited(n,false);

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                res++;
                bfs(i,isConnected,visited);
            }
        }
        return res;
    }
};