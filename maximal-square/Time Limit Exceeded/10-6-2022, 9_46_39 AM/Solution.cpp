// https://leetcode.com/problems/maximal-square

class Solution {
public:

    int dfs(vector<vector<char>>& matrix,int i,int j,int n,int m, vector<vector<int>>dp)
    {
        if(i<0 || j<0 || i>=n || j>=m || matrix[i][j]=='0')
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int right=dfs(matrix,i,j+1,n,m,dp);
        int down=dfs(matrix,i+1,j,n,m,dp);
        int diag=dfs(matrix,i+1,j+1,n,m,dp);
        return dp[i][j]=min({right,down,diag})+1;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    int cur=dfs(matrix,i,j,n,m,dp);
                    int cur_area=cur*cur;
                    res=max(res,cur_area);
                }
            }
        }
        return res;
    }
};