// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    int maxProfit(vector<int>& price) {
        int bs1=INT_MAX;
        int bs2=INT_MAX;
        int ps1=0;
        int ps2=0;
        for(int i=0;i<price.size();i++)
        {
            bs1=min(bs1,price[i]);
            ps1=max(ps1,price[i]-bs1);
            bs2=min(bs2,pirce[i]-ps1);
            ps2=max(ps2,price[i]-bs2);
        }
        return ps2;
    }
};