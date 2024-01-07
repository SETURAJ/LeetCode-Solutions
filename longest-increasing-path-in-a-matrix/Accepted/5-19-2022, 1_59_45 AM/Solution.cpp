// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:
    int dp[200][200]{};
    int maxPath,row,col;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        maxPath=0;
        row=matrix.size();
        col=matrix[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                maxPath=max(maxPath,solve(matrix,i,j,-1));
            
        }
        return maxPath;
    }
    int solve(vector<vector<int>>& mat,int i,int j,int prev)
    {
        if(i<0 || j<0 || i>=row || j>=col|| mat[i][j]<=prev)
            return 0;
        if(dp[i][j])
            return dp[i][j];
        return dp[i][j]=1+max({ solve(mat,i+1,j,mat[i][j]),
                                solve(mat,i,j+1,mat[i][j]),
                                solve(mat,i-1,j,mat[i][j]),
                                solve(mat,i,j-1,mat[i][j]),
                              });
    }
};