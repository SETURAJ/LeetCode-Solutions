// https://leetcode.com/problems/minimum-time-to-make-rope-colorful

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length();
        int res=0;
        int sum=neededTime[0];
        int maxc=neededTime[0];
        for(int i=1;i<n;i++)
        {
            if(colors[i]!=colors[i-1])
            {
                res+=sum-maxc;
                sum=0;
                maxc=0;
            }
            sum+=neededTime[i];
            maxc=max(maxc,neededTime[i]);
        }
        res+=sum-maxc;
        return res;
    }
};