// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    
    int lis(vector<int>&nums,int i,int prev,int n,vector<int>&dp)
    {
        if(i>=n)
            return 0;
       if(dp[prev+1]!=-1)
           return dp[prev+1];
        int take=0,donttake=lis(nums,i+1,prev,n,dp);
        if(prev==-1 || nums[i]>nums[prev])
            take=1+lis(nums,i+1,i,n,dp);
        return dp[prev+1]=max(take,donttake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return lis(nums,0,-1,n,dp);   
    }
};