// https://leetcode.com/problems/maximum-star-sum-of-a-graph

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size();
        vector<vector<int>>g(n);
        for(auto e:edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            priority_queue<int,vector<int>,greater<int>>pq;
            int sum=vals[i];
            for(int u:g[i])
            {
                pq.push(vals[u]);
                if(pq.size()>k)
                    pq.pop();
            }
            while(!pq.empty())
            {
                if(pq.top()>0)
                    sum+=pq.top();
                pq.pop();
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};