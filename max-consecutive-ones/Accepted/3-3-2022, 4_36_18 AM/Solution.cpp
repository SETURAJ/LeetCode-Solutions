// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,count=0;
        for(auto n:nums)
        {
            if(n==1)
            {
                count++;
                ans=max(ans,count);
            }
            else
                count=0;
        }
        return ans;
        
    }
};