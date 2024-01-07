// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array

class Solution {
public:
    
    vector<int> findlislr(vector<int>&nums)
    {
        vector<int>dp(nums.size(),1);
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && dp[i]<1+dp[j])
                    dp[i]=1+dp[j];
            }
        }
        return dp;
    }
     vector<int> findlisrl(vector<int>&nums)
    {
        vector<int>dp(nums.size(),1);
        int n=nums.size();
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(nums[i]>nums[j] && dp[i]<1+dp[j])
                    dp[i]=1+dp[j];
            }
        }
        return dp;
    }
    
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>dp1=findlislr(nums);
        vector<int>dp2=findlisrl(nums);
        int answer=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(dp1[i]==1 || dp2[i]==1)
                continue;
            answer=max(answer,dp1[i]+dp2[i]-1);
        }
        return nums.size()-answer;
    }
};