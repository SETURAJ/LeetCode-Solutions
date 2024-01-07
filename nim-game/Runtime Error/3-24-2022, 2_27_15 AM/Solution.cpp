// https://leetcode.com/problems/nim-game

class Solution {
public:
    bool canWinNim(int n) {
        if(n<=3)
            return true;
        if(n==4)
            return false;
        bool dp[n+1];
        dp[1]=dp[2]=dp[3]=true;
        dp[4]=false;
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