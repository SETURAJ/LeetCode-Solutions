// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    /*
    int findsub(int i,int j,string s,string t,vector<vector<int>>&dp)
    {
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j] =  findsub(i-1,j-1,s,t,dp) + findsub(i-1,j,s,t,dp);
        return dp[i][j] = findsub(i-1,j,s,t,dp);
    }
    */
    
    int numDistinct(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=l1;i++)
            dp[i][0] = 1;
        
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%1000000007;
                else
                    dp[i][j] = (dp[i-1][j])%1000000007;
            }
        }
        return dp[l1][l2];
        //return findsub(l1,l2,s,t,dp);
    }
};