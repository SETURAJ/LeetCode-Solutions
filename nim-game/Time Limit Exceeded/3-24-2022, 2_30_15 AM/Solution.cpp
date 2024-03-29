// https://leetcode.com/problems/nim-game

class Solution {
public:
    bool canWinNim(int n) {
        if(n<=3)
            return true;
        if(n==4)
            return false;
        vector<bool> dp(n,false);
        dp[1] = true;
        dp[2] = true;
        dp[3] = true;
        dp[4] = false;
        for(int i=5;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(dp[i-j]==false)
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};