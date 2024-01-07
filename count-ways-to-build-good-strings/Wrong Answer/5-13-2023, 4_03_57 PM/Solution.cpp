// https://leetcode.com/problems/count-ways-to-build-good-strings

class Solution {
public:

    int m=1e9+7;

    int func(int n,int zero,int one,vector<long long int>&dp)
    {
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        if(dp[n]!=-1)
            return dp[n]%m;
        int a=0,b=0;
        if(n>=zero)
            a=func(n-zero,zero,one,dp);
        if(n>=one)
            b=func(n-one,zero,one,dp);
        return dp[n]=(a+b)%m;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        long long int res=0;
        vector<long long int>dp(high+1,-1);
        for(int i=low;i<=high;i++)
        {
            res+=func(i,zero,one,dp)%m;
        }
        return res;
    }
};