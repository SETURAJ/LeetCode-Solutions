// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        int ans=0,buy=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            int temp=prices[i]-buy;
            ans=max(ans,temp);
            if(prices[i]<buy)
                buy=prices[i];
        }
        return ans;
    }
};