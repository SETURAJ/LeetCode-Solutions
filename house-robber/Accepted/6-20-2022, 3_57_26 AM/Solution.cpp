// https://leetcode.com/problems/house-robber

class Solution {
public:
    
    int find(int ind,vector<int>&nums,vector<int>&dp)
    {
        if(ind<0)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        if(ind==0 )
            return nums[ind];
        
        int pick=nums[ind]+find(ind-2,nums,dp);
        int notpick=find(ind-1,nums,dp);
        return dp[ind]=max(pick,notpick);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return find(n-1,nums,dp);
    }
};