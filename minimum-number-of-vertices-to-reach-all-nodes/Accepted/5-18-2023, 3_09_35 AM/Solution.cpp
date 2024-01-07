// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> isIncoming(n,false);
        for(vector<int>&edge:edges)
        {
            isIncoming[edge[1]]=true;
        }
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            if(!isIncoming[i])
                res.push_back(i);
        }
        return res;
    }
};