// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int right=0,left=0;
        int ans=INT_MAX;
        for(right=0;right<nums.size();right++)
        {
            sum+=nums[right];
            while(sum>=target)
            {
                ans=min(ans,right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};