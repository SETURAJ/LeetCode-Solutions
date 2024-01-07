// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    
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
    
    
    int numDistinct(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,-1));
        return findsub(l1,l2,s,t,dp);
    }
};