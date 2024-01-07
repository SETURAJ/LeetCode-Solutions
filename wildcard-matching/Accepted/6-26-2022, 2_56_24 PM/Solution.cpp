// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    
    bool isallstars(string s,int i)
    {
        for(int k=i;k>=0;k--)
        {
            if(s[k]!='*')
                return false;
        }
        return true;
    }
    
    bool find(int i,int j,string &s,string &p,vector<vector<bool>>&dp)
    {
        if(i<0 && j<0)
            return true;
        if(i<0 && j>=0)
            return isallstars(p,j);
        if(j<0 && i>=0)
            return isallstars(s,i);
        if(dp[i][j]==false)
            return dp[i][j];
        if(s[i]==p[j] && s[i]!='*')
            return dp[i][j]=find(i-1,j-1,s,p,dp);
        else if(s[i]!=p[j])
        {
            if(s[i]=='?' || p[j]=='?')
                return dp[i][j]=find(i-1,j-1,s,p,dp);
            else if(s[i]=='*' && p[j] !='*')
                return dp[i][j]=find(i,j-1,s,p,dp) || find(i-1,j-1,s,p,dp) || find(i-1,j,s,p,dp);
            else if(s[i]!='*' && p[j]=='*')
                return dp[i][j]=find(i-1,j,s,p,dp)|| find(i-1,j-1,s,p,dp) || find(i,j-1,s,p,dp);
            else if(s[i]=='*' && p[j]=='*')
                return dp[i][j]=find(i,j-1,s,p,dp) || find(i-1,j,s,p,dp) || find(i-1,j-1,s,p,dp);
        }
        return false;
    }
    
    bool isMatch(string s, string p) {
        int l1=s.length(),l2=p.length();
        vector<vector<bool>>dp(l1,vector<bool>(l2,true));
        return find(l1-1,l2-1,s,p,dp);
    }
};