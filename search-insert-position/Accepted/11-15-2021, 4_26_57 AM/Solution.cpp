// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int binarysearch(vector<int>& arr,int target)
    {
        int l=0,r=(int)arr.size()-1,mid,ans=-1;
        while(r>=l)
        {
            mid=(r+l)/2;
            if(arr[mid]==target)
                return mid;
            if(arr[mid]<target)
            {
                ans=mid+1;
                l=mid+1;
            }
            else
            {
                ans=mid;
                r=mid-1;
            }
                
        }
        return ans;
        
    }
    int searchInsert(vector<int>& nums, int target) {
        
       return binarysearch(nums,target);
    }
};