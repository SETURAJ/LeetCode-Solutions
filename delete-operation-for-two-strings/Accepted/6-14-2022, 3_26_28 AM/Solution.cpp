// https://leetcode.com/problems/delete-operation-for-two-strings

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        if(m==0 && n==0)
            return 0;
        if(m==0)
            return n;
        if(n==0)
            return m;
        vector<vector<int> >dp(m + 1, vector<int>(n + 1));
	    for(int i = 0; i <= m; i++) 
        {
            for(int j = 0; j <= n; j++)
            {
			    if(i==0 || j==0) 
                    dp[i][j] = i + j; 
			    else if(word1[i - 1] == word2[j - 1])
                    dp[i][j]=dp[i - 1][j - 1];
                else
                    dp[i][j]=1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};