// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        if(word1.length()==0)
            return word2.length();
        if(word2.length()==0)
            return word1.length();
        int l1=word1.length();
        int l2=word2.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1));
        for(int i=0;i<l1+1;i++)
            dp[i][0]=i;
        for(int j=0;j<l2+1;j++)
            dp[0][j]=j;
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                {
                    dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                }
            }
        }
        return dp[l1][l2];
    }
};