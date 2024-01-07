// https://leetcode.com/problems/jump-game

class Solution {
public:
    
    
    bool canJump(vector<int>& nums) {
        int pos=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==0 && pos==i)
                return false;
            else if(nums[i]+i>=pos)
                pos=nums[i]+i;
        }
        return pos>=nums.size()-1;
    }
};