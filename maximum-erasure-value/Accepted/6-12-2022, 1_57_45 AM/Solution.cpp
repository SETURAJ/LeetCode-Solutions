// https://leetcode.com/problems/maximum-erasure-value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>uset;
        int l=0,curr_sum=0,res=0;
        if(nums.size()==1)
            return nums[0];
        for(int num:nums)
        {
            while(uset.find(num)!=uset.end())
            {
                uset.erase(nums[l]);
                curr_sum-=nums[l];
                l++;
            }
            uset.insert(num);
            curr_sum+=num;
            res=max(res,curr_sum);
        }
        return res;
    }
};