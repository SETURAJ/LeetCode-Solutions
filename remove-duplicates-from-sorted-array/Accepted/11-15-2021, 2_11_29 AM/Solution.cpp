// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int j=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=nums[i+1])
                nums[j++]=nums[i];
            
        }
        nums[j++]=nums[n-1];
      
        return j;
            
    }
};