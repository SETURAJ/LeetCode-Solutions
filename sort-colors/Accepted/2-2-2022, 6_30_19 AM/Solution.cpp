// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int mid=0,l=0,r=n-1;
        while(mid<=r)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[l]);
                l++;
                mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[r]);
                r--;
            }
            else mid++;
        }
    }
};