// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    
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
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return findprofit(prices,0,1,n,dp);
    }
};