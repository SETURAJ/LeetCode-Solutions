// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1)
            return nums[0];
        for(int i=n-1;i>=0;i--)
        {
            k--;
            if(k==0)
                return nums[i];
        }
        return nums[0];
    }
};