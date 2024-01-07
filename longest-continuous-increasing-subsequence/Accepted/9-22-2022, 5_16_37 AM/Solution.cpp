// https://leetcode.com/problems/longest-continuous-increasing-subsequence

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count=0;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
                count++;
            else
            {
                if(nums[i]>nums[i-1])
                {
                    count++;
                    
                }
                else
                {
                    res=max(count,res);
                    count=1;
                }
            }
        }
        res=max(res,count);
        return res;
    }
};