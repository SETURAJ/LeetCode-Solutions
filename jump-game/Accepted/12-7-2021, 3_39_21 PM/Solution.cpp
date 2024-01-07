// https://leetcode.com/problems/jump-game

class Solution {
public:
    
    
    bool canJump(vector<int>& nums) {
        int maxr=0;
        for(int i=0;i<nums.size();i++)
        {
            if(maxr<i)
                return false;
            if(maxr>=nums.size())
                return true;
            maxr=max(maxr,nums[i]+i);
        }
        return true;
        
    }
};