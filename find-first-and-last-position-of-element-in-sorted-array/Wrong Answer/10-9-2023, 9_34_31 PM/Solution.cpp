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
        if(!nums.size()  || index == -1)
            return res;
        int start =index;
        int end =index;
        int j=index;
        cout<<index<<endl;
        
        for(int i=index;i>0;i--)
        {
            if(nums[i]==target)
                start=i;
        }
        
   
        for(int i=index;i<nums.size();i++)
        {
            if(nums[i]==target)
                end=i;
        }
        
        
        res[0]=start;
        res[1]=end;
        return res;
    }
};