// https://leetcode.com/problems/house-robber

class Solution {
public:
    
    int find(int ind,vector<int>&nums)
    {
        if(ind==0 )
            return nums[ind];
        if(ind<0)
            return 0;
        int pick=nums[ind]+find(ind-2,nums);
        int notpick=find(ind-1,nums);
        return max(pick,notpick);
    }
    
    int rob(vector<int>& nums) {
        return find(nums.size()-1,nums);
    }
};