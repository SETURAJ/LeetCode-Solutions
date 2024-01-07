// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    
    
    int find(int ind,int tranNo,vector<int>&prices,int n,int k,vector<vector<int>>&dp)
    {
        if(ind==n || tranNo==2*k)
            return 0;
        if(dp[ind][tranNo]!=-1)
                   return dp[ind][tranNo];
        if(tranNo%2==0)//buy
        {
            return dp[ind][tranNo]= max(-prices[ind]+find(ind+1,tranNo+1,prices,n,k,dp),0+find(ind+1,tranNo,prices,n,k,dp));
        }
        return dp[ind][tranNo]= max(prices[ind]+find(ind+1,tranNo+1,prices,n,k,dp),0+find(ind+1,tranNo,prices,n,k,dp));
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2*k,-1));
        return find(0,0,prices,n,k,dp);
    }
};