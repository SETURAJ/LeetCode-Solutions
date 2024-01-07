// https://leetcode.com/problems/max-points-on-a-line

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2)
            return n;
        int res=0;
        for(auto it1:points)
        {
            unordered_map<double,int>umap;
            double a=it1[0],b=it1[1];
            for(auto it2:points)
            {
                if(it1==it2)
                    continue;
                double c=it2[0],d=it2[1];
                double slope=0;
                if(c-a ==0)
                    slope=INT_MAX;
                else
                    slope=(d-b)/(c-a);
                umap[slope]++;
                res=max(res,umap[slope]);
            }
        }
        return res+1;
    }
};