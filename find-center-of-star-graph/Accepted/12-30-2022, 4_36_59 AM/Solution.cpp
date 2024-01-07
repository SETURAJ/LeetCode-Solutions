// https://leetcode.com/problems/find-center-of-star-graph

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>count(n+2);
        for(auto e:edges)
        {
            count[e[0]]++;
            count[e[1]]++;
        }
        for(int i=1;i<=n+1;i++)
        {
            if(count[i]==(n))
                return i;
        }
        return -1;
    }
};