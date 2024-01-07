// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int n=nums.size();
        int dup=-1;
        for(int i=0;i<n;i++)
        {
            int curr=abs(nums[i]);
            if(nums[curr]<0)
            {
                dup=curr;
                break;
            }
            nums[curr]*=(-1);
        }
        return dup;
        
    }
};