// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int index=abs(nums[i]);
            if(index>n-1)
                continue;
            else
            {
                nums[index]*=(-1);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                return i;
        }
        return n;
    }
};