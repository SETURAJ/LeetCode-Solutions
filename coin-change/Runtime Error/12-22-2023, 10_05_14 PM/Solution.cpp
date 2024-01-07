// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0 )
            return 0;
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(j==0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = INT_MAX;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
            }
        }
        return dp[n][amount];
    }
};