// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int last=points[0][1];
        int res=1;
        for(auto p:points)
        {
            if(p[0]>last)
            {
                res++;
                last=p[1];
            }
            last=min(last,p[1]);
        }
        return res;
    }
};