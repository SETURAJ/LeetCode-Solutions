// https://leetcode.com/problems/minimum-falling-path-sum-ii

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==1 && n==1)
            return grid[0][0];
        if(m==1)
        {
            int res=INT_MAX;
            for(int i=0;i<n;i++)
                res=min(res,grid[0][i]);
            return res;
        }
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
            dp[0][i]=grid[0][i];
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int prev=INT_MAX;
                for(int k=0;k<n;k++)
                {
                    if(k!=j)
                    {
                        int trace=dp[i-1][k]+grid[i][j];
                        prev=min(prev,trace);
                    }
                }
                dp[i][j]=prev;
            }
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++)
            res=min(res,dp[m-1][i]);
        return res;

    }
};