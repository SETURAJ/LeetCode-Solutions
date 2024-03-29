// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    
    int houseRob(vector<int>& nums) {
        int n=nums.size();
        if(n<=0)
            return 0;
        if(n==1)
            return nums[0];
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[n];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()<=0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        vector<int>v1(nums.begin(),nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        return max(houseRob(v1), houseRob(v2));
    }
};