// https://leetcode.com/problems/reverse-pairs

class Solution {
public:
    int res;
    void merge(vector<int>&nums,int left,int mid,int right)
    {
    
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
        return ;
       
    }
    
    void MergeSort(vector<int>&nums,int left,int right)
    {
        
        if(left>=right)
            return;
            int mid;
            mid=(left+right)/2;
            MergeSort(nums,left,mid);
            MergeSort(nums,mid+1,right);
            
            merge(nums,left,mid,right);
        
    }
    
    int reversePairs(vector<int>& nums) {
        if(!nums.size())
            return 0;
    
        MergeSort(nums,0,nums.size()-1);
        return res;
    }
};