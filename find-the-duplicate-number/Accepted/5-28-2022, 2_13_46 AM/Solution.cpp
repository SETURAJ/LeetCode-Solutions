// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int duplicate=-1;
        for(int i=0;i<n;i++)
        {
            int cur=abs(nums[i]);
            if(nums[cur]<0)
            {
                duplicate=cur;
                break;
            }
            nums[cur]*=(-1);
        }
        return duplicate;
        
    }
};