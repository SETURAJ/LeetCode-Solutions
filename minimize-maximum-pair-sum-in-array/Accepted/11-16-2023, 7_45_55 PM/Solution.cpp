// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res  INT_MIN;
        int h = nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            res = max(res,nums[i]+nums[h]);
            h--;
        }
        return res;
    }
};