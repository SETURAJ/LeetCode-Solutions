// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    
    
    int find(int ind,int tranNo,vector<int>&prices,int n,int k)
    {
        if(ind==n || tranNo==2*k)
            return 0;
        if(tranNo%2==0)//buy
        {
            return max(-prices[ind]+find(ind+1,tranNo+1,prices,n,k),0+find(ind+1,tranNo,prices,n,k));
        }
        return max(prices[ind]+find(ind+1,tranNo+1,prices,n,k),0+find(ind+1,tranNo,prices,n,k));
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        return find(0,0,prices,n,k);
    }
};