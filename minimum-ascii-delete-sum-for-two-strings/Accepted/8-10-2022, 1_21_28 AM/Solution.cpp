// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0 )
                    dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=s1[i-1]+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int total=0;
        for(int i=0;i<n;i++)
            total+=s1[i];
        for(int j=0;j<m;j++)
            total+=s2[j];
        return total - 2*dp[n][m];
    }
};