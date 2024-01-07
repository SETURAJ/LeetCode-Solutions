// https://leetcode.com/problems/longest-increasing-subsequence-ii

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        if(!nums.size())
            return 0;
        int n=nums.size();
        vector<int>dp(nums.size(),1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && nums[i]-nums[j]<=k && 1+dp[j]>dp[i])
                    dp[i]=1+dp[j];
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};