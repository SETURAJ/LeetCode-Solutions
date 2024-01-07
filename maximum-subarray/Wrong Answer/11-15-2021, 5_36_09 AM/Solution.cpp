// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max_ans=nums[0],max_till_now=nums[0];
        for(int i=0;i<n;i++)
        {
            if(max_ans<max_till_now)
                max_ans=max_till_now;
            else if(max_till_now<0)
                max_till_now=0;
            max_till_now+=nums[i];
        }
        return max_ans;
    }
};