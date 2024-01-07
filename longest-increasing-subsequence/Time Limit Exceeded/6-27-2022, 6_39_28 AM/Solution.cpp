// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    
    int lis(vector<int>&nums,int i,int prev,int n)
    {
        if(i>=n)
            return 0;
        int take=0,donttake=lis(nums,i+1,prev,n);
        if(nums[i]>prev)
            take=1+lis(nums,i+1,nums[i],n);
        return max(take,donttake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return lis(nums,0,INT_MIN,n);   
    }
};