// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome

class Solution {
public:
    
    int find_lcs(string s1,string s2)
    {
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1));
        for(int i=0;i<=s1.length();i++)
        {
            for(int j=0;j<=s2.length();j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[s1.length()][s2.length()];
    }    
    int minInsertions(string s) {
        string s_rev=s;
        reverse(s.begin(),s.end());
        
        int n=s.length();
        int l=find_lcs(s,s_rev);
        return n-l;
    }
};