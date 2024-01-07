// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
      int total=0,half=0;
        for(int i=0;i<nums.size();i++)
            total+=nums[i];
        if(total%2==1)
            return false;
        half=total/2;
        vector<bool>dp(half+1,false);
        dp[0]=true;
        for(auto n:nums)
        {
            for(int j=half;j>=n;j--)
            {
                if(dp[j-n])
                    dp[j]=true;
            }
        }
        return dp[half];
    }
};