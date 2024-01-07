// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        for(i=0;i<n;i++)
        {
            j=i;
            if(nums[i]==0)
            {
              while(j<n-1 && nums[j]==0)
              {
                  j++;
              }
                swap(nums[i],nums[j]);
            }
        }
        
    }
};