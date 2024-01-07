// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[0].size();
        if(m==1 && n==1)
            return triangle[0][0];
        vector<int>res=triangle[m-1];
        for(int i=m-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                res[j]=triangle[i][j]+min(res[j],res[j+1]);
            }
        }
        return res[0];
    }
};