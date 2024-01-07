// https://leetcode.com/problems/coin-change-ii

class Solution {
public:
    
    int findcoins(vector<int>&coins,int amount, int ind,int n)
    {
        if(amount==0)
            return 1;
        if(ind>=n && amount!=0)
            return 0;
        if(amount<0)
            return 0;

        return findcoins(coins,amount,ind+1,n) + findcoins(coins,amount-coins[ind],ind,n);
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return findcoins(coins,amount,0,n);
    }
};