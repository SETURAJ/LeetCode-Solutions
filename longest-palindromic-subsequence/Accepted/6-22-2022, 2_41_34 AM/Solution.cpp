// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    
    int lcs(string s1,string s2)
    {
        int l1=s1.length(),l2=s2.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[l1][l2];
    }
    
    int longestPalindromeSubseq(string s) {
        if(s.length()==1)
            return 1;
        string s1=s;
        reverse(s.begin(),s.end());
        return lcs(s1,s);
        
    }
};