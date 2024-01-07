// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    
    int houseRob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1)
                pick+=dp[i-2];
            int notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
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