// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int res = 0;
        int large = *max_element(nums.begin(),nums.end());
        int second_large = nums[0];
        int small = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            small = min(small,nums[i]);
            second_large = max(second_large,nums[i]);
        } 
        if(small == large)
            return 0;
        res = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==large && second_large != small)
            {
                res++;
            }
            else if(nums[i]!=small)
                res++;
        }
        return res;
    }
};