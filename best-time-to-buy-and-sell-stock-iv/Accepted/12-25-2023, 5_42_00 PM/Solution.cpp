// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    /*
    int findprofit(vector<int>&prices,int ind,int buy,int cap,int n)
    {
        if(ind==n || cap==0)
            return 0;
        if(buy==1)
        {
            return max(-prices[ind]+findprofit(prices,ind+1,0,cap,n) , 0 + findprofit(prices,ind+1,1,cap,n));
        }
        return max(prices[ind]+findprofit(prices,ind+1,1,cap-1,n) , 0 + findprofit(prices,ind+1,0,cap,n));
    }
    */
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int ind = n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=k;cap++)
                {
                    if(buy==1)
                        dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap] , 0 + dp[ind+1][1][cap]);
                    else
                        dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1] , 0 + dp[ind+1][0][cap]);
                }
            }
        }
        return dp[0][1][k];
    }
};