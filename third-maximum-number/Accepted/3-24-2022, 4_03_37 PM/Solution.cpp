// https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        long one = LONG_MIN, two = LONG_MIN, three = LONG_MIN;
        
        for(int num:nums)
        {
            if(num==one || num==two || num==three)
                continue;
            if(num>one)
            {
                three=two;
                two=one;
                one=num;
            }
            else if(num>two)
            {
                three=two;
                two=num;
            }
            else if(num>three)
                three=num;
        }
        return three==LONG_MIN ? one:three;
        
    }
};