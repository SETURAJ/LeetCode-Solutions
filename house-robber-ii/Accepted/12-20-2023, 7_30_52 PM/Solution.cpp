// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        int n =nums.size();
        int res1=INT_MIN,res2=INT_MIN;
        vector<int>dp(n+1,0);
        dp[1] = nums[0];
        dp[2] = max(nums[0],nums[1]);
        
        for(int i=3;i<n;i++)
        {
            dp[i] = max(dp[i-1],nums[i-1]+dp[i-2]);
        }
        res1=dp[n-1];
        vector<int>dp2(n+1,0);
        for(int i=2;i<=n;i++)
        {
            dp2[i] = max(dp2[i-1],nums[i-1]+dp2[i-2]);
        }
         res2=dp2[n];
        cout<<res1<<" "<<res2<<endl;
        return max(res1,res2);
        
    }
};