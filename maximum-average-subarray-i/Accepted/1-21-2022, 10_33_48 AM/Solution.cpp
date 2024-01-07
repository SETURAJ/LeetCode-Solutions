// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double maxsum=0;
        for(int i=0;i<k;i++)
        {
            maxsum+=nums[i];
        }
        if(k==n)
            return maxsum/k;
        
        double sum=maxsum;
        for(int i=k;i<n;i++)
        {
            
            sum-=nums[i-k];
            sum+=nums[i];
            maxsum=max(maxsum,sum);
        }
        return maxsum/k;
    }
};