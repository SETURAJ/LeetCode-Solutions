// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:
    
    int findpath(vector<vector<int>>&matrix,int i,int j,int n,int m, int val,vector<vector<int>>&dp)
    {
        if(i<0 || i>=n || j<0 || j>=m || matrix[i][j] <= val)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j] = 1 + max({findpath(matrix,i+1,j,n,m,matrix[i][j],dp),
                        findpath(matrix,i,j+1,n,m,matrix[i][j],dp),
                        findpath(matrix,i-1,j,n,m,matrix[i][j],dp),
                        findpath(matrix,i,j-1,n,m,matrix[i][j],dp)
                        });
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = INT_MIN;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int size = findpath(matrix,i,j,n,m,-1,dp);
                res = max(res,size);
            }
        }
        return res;
    }
};