// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    
    int findprofit(vector<int>&prices,int ind,int buy,int n)
    {
        if(ind>=n)
            return 0;
        if(buy==1)
        {
            return max(-prices[ind]+findprofit(prices,ind+1,0,n),0+ findprofit(prices,ind+1,1,n));
        }
        return max(prices[ind]+findprofit(prices,ind+2,1,n), 0+ findprofit(prices,ind+1,0,n));
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return findprofit(prices,0,1,n);
    }
};