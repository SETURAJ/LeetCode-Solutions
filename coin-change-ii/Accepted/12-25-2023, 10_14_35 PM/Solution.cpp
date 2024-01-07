// https://leetcode.com/problems/coin-change-ii

class Solution {
public:
    
    int findcoins(vector<int>&coins,int amount, int ind,int n,vector<vector<long long int>>&dp)
    {
        if(amount==0)
            return 1;
        if(ind>=n && amount!=0)
            return 0;
        if(amount<0)
            return 0;
        if(dp[amount][ind]!=-1)
            return dp[amount][ind];
        return dp[amount][ind]= findcoins(coins,amount,ind+1,n,dp) + findcoins(coins,amount-coins[ind],ind,n,dp);
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long int>>dp(amount+1,vector<long long int>(n+1,-1));
        return findcoins(coins,amount,0,n,dp);
    }
};