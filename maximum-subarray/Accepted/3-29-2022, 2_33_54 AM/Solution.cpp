// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int res;
        if(n<1)
            return res;
        vector<int>dp(n);
        dp[0]=nums[0];
        res=dp[0];
        if(n==1)
            return res;
        for(int i=1;i<n;i++)
        {
            dp[i]=nums[i]+(dp[i-1]>0? dp[i-1]:0);
            res=max(res,dp[i]);
        }
        return res;
        
    }
};