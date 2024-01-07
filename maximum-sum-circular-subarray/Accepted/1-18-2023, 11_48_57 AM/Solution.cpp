// https://leetcode.com/problems/maximum-sum-circular-subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int total_sum=0;
        int max_sum=INT_MIN;
        for(int i=0;i<n;i++)
            total_sum+=nums[i];
        int min_sum=INT_MAX;
        int min_end=INT_MAX;
        int sum1=0;
        for(int i=0;i<n;i++)
        {
            sum1+=nums[i];
            max_sum=max(max_sum,sum1);
            if(sum1<0)
                sum1=0;
            if(min_end>0)
                min_end=nums[i];
            else
                min_end+=nums[i];
            min_sum=min(min_sum,min_end);
        }
        return (total_sum==min_sum)?max_sum:max(max_sum,total_sum-min_sum);
    }
};