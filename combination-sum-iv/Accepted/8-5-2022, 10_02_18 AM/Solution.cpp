// https://leetcode.com/problems/combination-sum-iv

class Solution {
public:
    vector<int>dp;
   
    int find(vector<int>nums,int target,int n)
    {
        if(target==0)
        {
            return 1;
        }
        int ans=0;
        if(dp[target]!=-1)
            return dp[target];
        for(int i=0;i<n;i++)
        {
            if(target>=nums[i])
                ans+=find(nums,target-nums[i],n);
        }
        dp[target]=ans;
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        dp.resize(target+1,-1);
        return find(nums,target,nums.size());
        
    }
};