// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    /*
    int findprofit(vector<int>&prices,int ind,int buy,int n,vector<vector<int>>&dp)
    {
        if(ind>=n)
            return 0;
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        if(buy==1)
        {
            return dp[ind][buy]=max(-prices[ind]+findprofit(prices,ind+1,0,n,dp),0+ findprofit(prices,ind+1,1,n,dp));
        }
        return dp[ind][buy]=max(prices[ind]+findprofit(prices,ind+2,1,n,dp), 0+ findprofit(prices,ind+1,0,n,dp));
    }
    
    */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy==1)
                {
                    dp[ind][buy]=max(-prices[ind]+dp[ind+1][0],0+ dp[ind+1][1]);
                }
                else
                    dp[ind][buy]=max(prices[ind]+dp[ind+2][1],0+dp[ind+1][0]);
            }
        }
        
        return dp[0][1];
    }
};