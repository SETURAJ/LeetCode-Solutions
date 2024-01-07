// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    /*
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
    */
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.length() + s2.length())!=s3.length())
            return false;
        int l1=s1.length();
        int l2=s2.length();
        vector<vector<bool>>dp(l1+1,vector<bool>(l2+1));
        dp[0][0] = true;
        for(int i=1;i<=l1;i++)
            dp[i][0] = dp[i-1][0] && (s1[i-1] && s3[i-1] );
        for(int j=1;j<=l2;j++)
            dp[0][j] = dp[0][j-1] && (s2[j-1] && s3[j-1] );
        
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                dp[i][j] = ( dp[i-1][j]  &&   (s1[i-1] == s3[i+j-1]) ) || (  dp[i][j-1]  && (s2[j-1] == s3[i+j-1])); 
            }
        }
        
        
        return dp[s1.length()][s2.length()];
        
        //return isvalid(s1,s2,s3,0,0,0,dp);
    }
};