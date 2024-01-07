// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==1 && n==1)
            return matrix[0][0];
        if(m==1)
        {
            int res=INT_MAX;
            for(int i=0;i<n;i++)
                res=min(matrix[0][i],res);
            return res;
        }
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
            dp[0][i]=matrix[0][i];
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int down=matrix[i][j]+dp[i-1][j];
                int leftdiag=INT_MAX,rightdiag=INT_MAX;
                if(j-1>=0)
                {
                    leftdiag=matrix[i][j]+dp[i-1][j-1];
                }
                if(j+1<n)
                    rightdiag=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min(down,min(leftdiag,rightdiag));
            }
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++)
            res=min(dp[m-1][i],res);
        return res;
    }
};