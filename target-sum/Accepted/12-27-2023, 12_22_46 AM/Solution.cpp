// https://leetcode.com/problems/target-sum

class Solution {
public:
    
    int ways(vector<int>&nums,int ind,int n, int target)
    {
        if(ind==n && target==0)
            return 1;
        if(ind==n && target!=0)
            return 0;
        return ways(nums,ind+1,n,target - nums[ind]) + ways(nums,ind+1,n,target+nums[ind]);
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return ways(nums,0,n,target);
    }
};