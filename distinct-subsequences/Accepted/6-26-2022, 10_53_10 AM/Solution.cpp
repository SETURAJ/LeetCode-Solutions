// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    
    int find(int i,int j,string &s,string &t, vector<vector<int>>&dp)
    {
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j]=find(i-1,j-1,s,t,dp) + find(i-1,j,s,t,dp);
        else
            return dp[i][j]=find(i-1,j,s,t,dp);
    }
    
    int numDistinct(string s, string t) {
        int l1=s.length(),l2=t.length();
        vector<vector<int>>dp(l1,vector<int>(l2,-1));
        return find(l1-1,l2-1,s,t,dp);
    }
};