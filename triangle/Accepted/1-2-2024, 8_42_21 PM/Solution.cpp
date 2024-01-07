// https://leetcode.com/problems/triangle

class Solution {
public:
    /*
    int minpath(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&memo)
    {
        if(i==triangle.size())
            return 0;
        if(memo[i][j]!=-1)
            return memo[i][j];
        return memo[i][j]= triangle[i][j] + min(minpath(i+1,j,triangle,memo),minpath(i+1,j+1,triangle,memo));
    }
    */
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        
        vector<vector<int>>dp(m,vector<int>(m,INT_MAX));
        
        for(int i=0;i<m;i++)
            dp[m-1][i] = triangle[m-1][i];  //for last row the dp can be filled as we starting from bottom so only one                                             //choice
        for(int i=m-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
                dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
        }
        return dp[0][0];
        
        
        //vector<vector<int>>memo(m,vector<int>(m,-1));
        //return minpath(0,0,triangle,memo);
    }
};