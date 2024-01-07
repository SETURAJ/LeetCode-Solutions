// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    
    bool isvalid(string s1,string s2,string s3,int i,int j,int k,vector<vector<int>>&dp)
    {
        if(k==s3.length())
            return true;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i<s1.length() && s1[i]==s3[k])
        {
            if(isvalid(s1,s2,s3,i+1,j,k+1,dp))
                return dp[i][j] = true;
        }
        
        if(j<s2.length() && s2[j]==s3[k])
        {
            if(isvalid(s1,s2,s3,i,j+1,k+1,dp))
                return dp[i][j]=true;
        }
        return dp[i][j]=false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.length() + s2.length())!=s3.length())
            return false;
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return isvalid(s1,s2,s3,0,0,0,dp);
    }
};