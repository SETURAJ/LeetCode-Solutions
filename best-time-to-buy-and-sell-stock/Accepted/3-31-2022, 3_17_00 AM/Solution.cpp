// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0||prices.size()==1)
            return 0;
        int ans=0,buy_value=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            int temp=prices[i]-buy_value;
            if(temp>ans)
                ans=temp;
            if(prices[i]<buy_value)
                buy_value=prices[i];
            
        }
        return ans;
    }
};