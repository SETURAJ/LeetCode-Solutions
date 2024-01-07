// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    /*
    int findprofit(vector<int>&prices,int ind,int buy,int fee , int n)
    {
        if(ind==n)
            return 0;
        if(buy==1)
            return max(-prices[ind]+findprofit(prices,ind+1,0,fee,n) , findprofit(prices,ind+1,1,fee,n));
        return max(prices[ind]-fee+findprofit(prices,ind+1,1,fee,n) , findprofit(prices,ind+1,0,fee,n));
    }
    */
    /*
    int findprofit(vector<int>&prices,int ind,int buy,int fee , int n,vector<vector<int>>&dp)
    {
        if(ind==n)
            return 0;
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        if(buy==1)
            return dp[ind][buy]= max(-prices[ind]+findprofit(prices,ind+1,0,fee,n,dp) , findprofit(prices,ind+1,1,fee,n,dp));
        return dp[ind][buy] = max(prices[ind]-fee+findprofit(prices,ind+1,1,fee,n,dp) , findprofit(prices,ind+1,0,fee,n,dp));
    }
    */
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy==1)
                    dp[ind][buy] = max(-prices[ind] + dp[ind+1][0] , dp[ind+1][1]);
                else
                    dp[ind][buy] = max(prices[ind]-fee + dp[ind+1][1] , dp[ind+1][0]);
            }
        }
        return dp[0][1];
        //return findprofit(prices,0,1,fee,n,dp);
    }
};