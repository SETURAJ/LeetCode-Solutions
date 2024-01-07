// https://leetcode.com/problems/regular-expression-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        bool dp[m+1][n+1];
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                dp[i][j]=false;
            }
        }
        
        dp[0][0]=true;
        for(int i=1;i<=n;i++)
        {
            if(p[i-1]=='*')
            {
                dp[0][i]=dp[0][i-2];
            }
        }
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(p[j-1]==s[i-1] || p[j-1]=='.')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i][j-2];
                    if(p[j-2]==s[i-1] || p[j-2]=='.')
                        if(dp[i-1][j])
                            dp[i][j]=dp[i-1][j];
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