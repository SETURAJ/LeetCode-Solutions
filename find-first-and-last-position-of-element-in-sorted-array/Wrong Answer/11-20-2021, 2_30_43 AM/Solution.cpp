// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    int binarysearch(vector<int>&nums,int l,int r,int target,int &start,int &end)
    {
        while(r>=l)
        {
            int mid=(l+r)/2;
            if(nums[mid]==target)
            {
                start=mid;
                end=mid;
                return 1;
            }
            else if(nums[mid]>target)
                return binarysearch(nums,l,mid-1,target,start,end);
            else return binarysearch(nums,mid+1,r,target,start,end);
                
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,start,end;
        int r=nums.size()-1;
    
    vector<int>res(2);
        res[0]=-1;
        res[1]=-1;
    if(nums.size()==0 || binarysearch(nums,l,r,target,start,end)==-1)
        return res;
    for(int i=end;i<nums.size();i++)
    {
        if(nums[i]==target)
            end=i;
    }
    for(int i=0;i<start;i++)
    {
        if(nums[i]==start)
            start=i;
    }
        res[0]=start;
        res[1]=end;
    return res;
    }
};