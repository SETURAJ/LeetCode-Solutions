// https://leetcode.com/problems/reverse-pairs

class Solution {
public:
    int inv_count=0;
    int merge(vector<int>&nums,int left,int mid,int right)
    {
        int res=0;
        int l=left,r=mid+1;
        while(l<=mid && r<=right)
        {
            if(nums[l]>(long)2*nums[r])
            {
                res+=(mid-l+1);
                r++;
            }
            else
                l++;
        }
        sort(nums.begin()+left,nums.begin()+right+1);
        return res;
       
    }
    
    int MergeSort(vector<int>nums,int left,int right)
    {
        int mid;
        if(right>left)
        {
            mid=(left+right)/2;
            inv_count+=MergeSort(nums,left,mid);
            inv_count+=MergeSort(nums,mid+1,right);
            
            inv_count+=merge(nums,left,mid,right);
        }
        return inv_count;
    }
    
    int reversePairs(vector<int>& nums) {
  
        return MergeSort(nums,0,nums.size()-1);
    }
};