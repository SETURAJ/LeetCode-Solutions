// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return 0;
        int jump=1,currjmp=nums[0],maxjmp=nums[0];
        int i=0;
        while(i<n-1)
        {
            maxjmp=max(maxjmp,nums[i]+i);
            if(currjmp==i)
            {
                jump++;
                currjmp=maxjmp;
            }
            i++;
        }
        return jump;
    }
};