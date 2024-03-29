// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(price.size()==0 || price.size()==1)
            return 0;
        int maxprofit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
                maxprofit+=prices[i]-prices[i-1];
        }
        return maxprofit;
    }
};