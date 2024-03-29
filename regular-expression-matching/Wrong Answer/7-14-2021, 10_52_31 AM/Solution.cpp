// https://leetcode.com/problems/regular-expression-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        bool dp[m+1][n+1];
        dp[0][0]=true;
        for(int i=1;i<=n;i++)
        {
            if(p[i-1]=='*')
            {
                return dp[0][i-2];
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='.')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i][j-2];
                    if(s[i-1]==p[j-2] || p[j-2]=='.')
                        dp[i][j]?dp[i][j]:dp[i-1][j];
                }
                else
                {
                    dp[i][j]=false;
                }
            }
        }
        return dp[m][n];
    }
};