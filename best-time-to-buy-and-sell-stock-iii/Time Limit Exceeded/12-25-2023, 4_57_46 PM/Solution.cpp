// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    
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
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return findprofit(prices,0,1,2,n);
    }
};