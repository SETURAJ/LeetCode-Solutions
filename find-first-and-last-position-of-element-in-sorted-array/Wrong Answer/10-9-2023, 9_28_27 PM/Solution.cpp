// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    
    int binarysearch(vector<int> nums, int l, int r, int target)
    {
        if(r>=l)
        {
            int mid = (l+r)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                return binarysearch(nums,l,mid-1,target);
            else
                return binarysearch(nums,mid+1,r,target);
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int index=-1;
        vector<int> res(2,-1);
        index = binarysearch(nums,0,nums.size()-1,target);
        if(nums.size() < 2 || index == -1)
            return res;
        int start , end =index;
        int i = index;
        while(i-- && nums[i]==target)
            start = i;
        i=index;
        while(i<nums.size() && nums[i]==target)
        {
            end=i;
            i++;
        }
        res[0]=start;
        res[1]=end;
        return res;
    }
};