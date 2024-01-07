// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2==1)
            return false;
        int find = sum/2;
        vector<int>dp(find+1,false);
        dp[0]=true;
        for(auto num:nums)
        {
            for(int j=find;j>=num;j--)
            {
                if(dp[j-num])
                    dp[j]=true;
            }
        }
        return dp[find];
    }
};