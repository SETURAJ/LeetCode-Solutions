// https://leetcode.com/problems/jump-game

class Solution {
public:
    
    
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return true;
        vector<int>dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n-1;i++)
        {
            if(dp[i-1]<i)
                return false;
            dp[i]=max(i+nums[i],dp[i-1]);
            if(dp[i]>=n-1)
                return true;
        }
        return dp[n-2]>=n-1;
    }
};