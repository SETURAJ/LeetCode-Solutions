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
        double ans=0;
        if(k==n)
        {
            ans=maxsum/k;
            return ans;
        }
        
        for(int i=k;i<n;i++)
        {
            double sum=maxsum;
            sum-=nums[i-k];
            sum+=nums[i];
            maxsum=max(maxsum,sum);
        }
        ans=maxsum/k;
        return ans;
    }
};