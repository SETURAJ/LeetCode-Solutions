// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int res=nums[0];
        int max_till=nums[0];
        for(int i=1;i<n;i++)
        {
            if(max_till<0)
                max_till=0;
            max_till+=nums[i];
            res=max(res,max_till);
        }
        return res;
        
    }
};