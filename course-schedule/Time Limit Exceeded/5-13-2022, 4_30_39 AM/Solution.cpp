// https://leetcode.com/problems/course-schedule

class Solution {
public:
    
    bool finder(int v,vector<int>graph[],vector<bool>visited,vector<bool>recstack)
    {
        if(visited[v]==false)
        {
            visited[v]=true;
            recstack[v]=true;
            for(auto it=graph[v].begin();it!=graph[v].end();it++)
            {
                if(!visited[*it] && finder(*it,graph,visited,recstack))
                    return true;
                else if(recstack[*it])
                    return true;
            }
        }
        recstack[v]=false;
        return false;
    }
    
    bool iscycle(vector<int>graph[],int V)
    {
        vector<bool>visited(V,false);
        vector<bool>recstack(V,false);
        for(int i=0;i<V;i++)
        {
            if(finder(i,graph,visited,recstack))
                return true;
        }
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>graph[numCourses];
        for(auto edge:prerequisites)
        {
            graph[edge[1]].emplace_back(edge[0]);
        }
        return !iscycle(graph,numCourses);
    }
};