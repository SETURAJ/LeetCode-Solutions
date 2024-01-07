// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:

    
    int numDistinct(string s, string t) {
        int l1=s.length(),l2=t.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        for(int i=0;i<l1+1;i++)
            dp[i][0]=1;
        for(int j=1;j<l2+1;j++)
            dp[0][j]=0;
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%100000001;
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[l1][l2];
        
    }
};