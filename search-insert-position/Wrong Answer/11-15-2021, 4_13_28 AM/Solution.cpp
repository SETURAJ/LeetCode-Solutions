// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int binarysearch(vector<int>& arr,int l,int r,int target)
    {
        if(r>=l)
        {
            int mid=(r+l)/2;
            if(arr[mid]==target)
                return mid;
            if(arr[mid]<target)
            {
                if(arr[mid+1]>=target)
                    return mid+1;
                else
                    return binarysearch(arr,mid+1,r,target);
            }
            if(arr[mid]>target)
            {
                if(arr[mid-1]<=target)
                    return mid-1;
                else
                    return binarysearch(arr,l,mid-1,target);
            }
        }
       return -1;
    }
    int searchInsert(vector<int>& nums, int target) {
        
        int l=0,r=nums.size()-1;
        return binarysearch(nums,l,r,target);
    }
};